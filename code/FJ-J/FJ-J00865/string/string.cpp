#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],ans=0,sum=1;
string b[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++)ans+=a[i];
	for(int i=1;i<=n-1;i++){
		if(b[i]!=b[i+1]){
			sum++;
		}
	}
	if(sum==1){
		cout<<0;
		return 0;
	}
	if(ans<=sum*2){
		cout<<sum-1;
	}else if(sum%2==0){
		cout<<ans/2;
	}else{
		cout<<ans/sum; 
	}
	return 0;
	
}
