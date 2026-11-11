#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int w[200005][35];
bitset<200005>bs[35];
void f(int i,int x){
	int pos=0;
	while(x){
		w[i][pos]+=x%2;
		w[0][pos]+=x%2;
		bs[pos][i]=x%2;
		x/=2;
		pos++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		f(i,arr[i]);
	}
	int ans=0,x=-1;
	for(int i=32;i>=0;i--){
		if(w[0][i]>=m){
			x=i;
			break;
		}
	}
	if(x==-1){
		cout<<0;
		return 0;
	}
	bitset<200005>pbs;
	pbs=bs[x];
	ans=1;
	for(int i=x-1;i>=0;i--){
		ans*=2;
		bitset<200005>b;
		b=pbs&bs[i];
		if(int(b.count())>=m){
			pbs&=bs[i];
			ans++;
		}
	}
	cout<<ans;
}
