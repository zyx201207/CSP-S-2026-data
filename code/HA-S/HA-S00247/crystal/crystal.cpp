#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0,f=1;
	cin>>n>>m;
	int l=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==k){
			if(l-k>=0){
				l-=k;
				ans++;
			}
		}else{
			f=0,ans=0,l=m;
			break;
		}	
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			if(l-i>=0){
				l-=i;
				ans++;
			}	
		}
	}
	cout<<ans;
	return 0;
}
