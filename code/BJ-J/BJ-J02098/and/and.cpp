#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[10005];
long long ch[100005];
int te=1,n,m,u=1;
bool check(long long y){
	int nu=1;
	while(y>0) {
		y-=ch[nu++];
		}
	if(y) return 0;
	return 1;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	cin>>n>>m;
	ch[1]=1;
	for(int i=2;i<=10;i++){
		ch[i]=ch[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(check(a[i])){
			b[u++]=a[i];
			}
	}
	if(m==n){
		te=a[1];
		for(int i=2;i<=n;i++){
			te&=a[i];
		}
		cout<<te;
		return 0;
	}
		sort(b+1,b+u);
		if(m<=u-1){
			cout<<b[u-1-m];
			}
return 0;
}