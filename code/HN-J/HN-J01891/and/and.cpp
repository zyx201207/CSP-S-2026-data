#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int mx=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}else if(n==m){
		int sum=0;
		for(int i=1;i<=n;i++) sum&=a[i];
		cout<<sum;
	} else{
		while(m--){
			int sum=0;
			for(int i=1;i<=n;i++)
			cout<<0;
		}
	}
	return 0;
}
