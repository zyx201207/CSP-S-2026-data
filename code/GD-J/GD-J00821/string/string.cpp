#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
string s;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	reverse(s.begin(),s.end());
	s1=s;
	reverse(s.begin(),s.end());
	if(s==s1){
		cout<<0;
	}else{
		int length=s.size()-1;
		int ans=0;
		for(int i=0;i<=length;i++){
			if(s[i]!=s1[i]){
				ans++;
				s[i]=s1[i];
				s1[length-i]=s[i];
			}
		}
		cout<<ans;
	}
	return 0;
} 
