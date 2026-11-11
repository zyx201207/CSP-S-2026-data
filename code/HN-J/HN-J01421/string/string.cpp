#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,xb=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int sz;
		char zm;
		cin>>sz>>zm;
		for(int i=1;i<=sz;i++){
			s[xb]=zm;
			//cout<<s[xb]<<" ";
			xb++;
		}
	} 
	int sum=0,ans=0;
//	cout<<s[0]<<" ";
//	for(int i=0;i<xb;i++){
//		cout<<s[i];
//	}
	for(int i=0;i<xb/2;i++){
		if(s[i]!=s[xb-i]) sum++;
	}
	for(int i=xb/2;i<xb;i++){
		int y=xb-i;
		if(s[i]!=s[xb-y]) ans++;
	}
	int minn=min(sum,ans);
	
	if(ans==0){
		cout<<sum;
		return 0;
	} 
	if(sum==0){
		cout<<ans;
		return 0;
	}
	//cout<<"sum="<<sum<<" ans="<<ans<<endl;
	cout<<minn;
	return 0;
} 

 
