#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200008];
long long ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ans=a[0];
	if(m==n){
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	return 0;
}
