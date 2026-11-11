#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
long long front[500005];
bool check(int from,int bas){
	long long to=(bas-from)*a[bas];
	long long now=front[bas-1]-front[from-1];
	if (to-now<=m)return 1;
	else return 0;
}
int erfen(int l,int r,int dest){
	if (dest==1)return 1;
	if (dest==2){
		if (check(1,2)){
			return 2;
		}
		else return 1;
	}
	if (l==r){
		if (check(l,dest)){
			return dest-l+1;
		}
		else return dest-1;
	}
	if (r==l+1){
		if (check(l,dest)){
			return dest-l+1;
		}
		else{
			if (check(r,dest))return dest-r+1;
			else return dest-r;
		}
	}
	int mid=(l+r)/2;
	if (check(mid,dest)){
		return erfen(l,mid,dest);
	}
	else{
		return erfen(mid,r,dest);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int least=a[1];

	for (int i=1;i<=n;i++)a[i]-=least;
	int hand=0;
	front[1]=a[1];
	front[0]=0;
	for (int i=2;i<=n;i++){
		front[i]=a[i]+front[i-1];
	}
	for (int i=1;i<=n;i++){
		hand=max(hand,erfen(1,i-1,i));
	}
	printf("%d",hand);
	return 0;
}
