#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	unsigned long long int n,m,a[200005],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1] and a[2];
		for(int i=2;i<=n-1;i++){
			ans=ans and a[i+1];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		ans=-1;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;i<=n;j++){
				long long k=a[i] and a[j];
				if(k>ans) ans=k;
			}
		}
		cout<<ans;
	}
}
