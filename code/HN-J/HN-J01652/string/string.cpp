#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		if(mp[c]==0){
			cnt++;
			mp[c]=a;
		}
	}
	if(cnt==1)cout<<0;
	else if(sum%cnt!=0)cout<<sum/cnt+1;
	else cout<<sum/cnt;
	return 0;
} 
