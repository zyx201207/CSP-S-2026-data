#include<bits/stdc++.h>
using namespace std;
bool b[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	string s="";
	long long n,t[200000],ans=0;
	char a[200000];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>t[i]>>a[i];
	for(int i=1;i<=n;i++){
		if(t[i]==t[n-i+1]&&i!=n-i+1){
			if(a[i]!=a[n-i+1]&&!b[i]){
				ans+=t[i];
				b[n-i+1]=1;
			}
		}
		else{
			for(int j=1;j<=t[i];j++)
				s+=a[i];
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i]) ans++;
	}
	cout<<ans;
	return 0; 
} 
