#include<bits/stdc++.h>
using namespace std;//freopen!!!!!!!!!!!!
	long long n,a,cnt=0,ans=0;
	char c;
	string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		cnt+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	if(cnt%2!=0){
		long long mid=(cnt+1)/2;
		string ss="";
		for(int i=cnt-1;i>=mid-1;i--){
			ss+=s[i];
		}
//		cout<<ss<<endl;
		for(int i=0;i<=mid-1;i++){
			if(s[i]!=ss[i]){
				ans++;
			}
		}
		cout<<ans;
	}
	else{
		long long mid=cnt/2;
		string ss="";
		for(int i=cnt-1;i>=mid;i--){
			ss+=s[i];
		}
//		cout<<ss<<endl;
		for(int i=0;i<=mid-1;i++){
			if(s[i]!=ss[i]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}

