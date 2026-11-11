#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[500000],ans=0,dq,c[500000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=(1<<30);i>=1;i>>=1){
		dq=0;
		for(int r=1;r<=n;r++){
			if(a[r]&i){dq++;c[dq]=a[r];}
		}
		if(dq>=m){
			ans+=i;
			n=dq;
			for(int r=1;r<=n;r++){
				a[r]=c[r];
			}
		}
	}
	cout<<ans;
	return 0;
}
