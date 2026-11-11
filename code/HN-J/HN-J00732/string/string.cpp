#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,c;
ll n,a,l,ans;
void hw(string h){
	string s1="",s2="";
	if(l%2==0){
		for(int i=0;i<l/2;i++){
			s1+=s[i];
		}
		for(int i=l-1;i>=l/2;i--){
			s2+=s[i];
		}
		if(s1==s2){
			ans=0;
			return ;
		}else{
			int l1=s1.size();
			for(int i=0;i<l1;i++){
				if(s1[i]!=s2[i]) ans++;
			}
			return ;
		}
	}else{
		for(int i=0;i<l/2;i++){
			s1+=s[i];
		}
		for(int i=l-1;i>l/2;i--){
			s2+=s[i];
		}
		if(s1==s2){
			ans=0;
			return ;
		}else{
			int l1=s1.size();
			for(int i=0;i<l1;i++){
				if(s1[i]!=s2[i]) ans++;
			}
			return ;
		}
	}
	return ;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
		l+=a;
	}
	hw(s);
	cout<<ans;
	return 0;
}
