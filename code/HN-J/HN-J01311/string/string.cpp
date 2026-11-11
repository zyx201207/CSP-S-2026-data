#include<bits/stdc++.h>
using namespace std;
long long n,a,ans,cnt;
char c;
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	for(int i=0;i<(s.size()-1)/2+1;i++){
		s1+=s[i];
	}
	for(int i=s.size()-1;i>=(s.size()-1)/2;i--){
		s2+=s[i];
	}
	if(s1==s2) cout<<'0';
	else{
		for(int i=0;i<s1.size();i++){
			if(s1[i]==s2[i]){
		
			}else{
				ans++;
			}
		} 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
