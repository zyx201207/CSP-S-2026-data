#include<bits/stdc++.h>
using namespace std;
int ans,n,a[200010];
char c[200010];
string s1="",s2="",s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	int l=0;
	while(s1.size()!=s.size()/2){
		s1+=s[l];
		l++;
	}
	l=s.size()-1;
	while(s2.size()!=s.size()/2){
		s2+=s[l];
		l--;
	}
	l=s1.size();
	for(int i=0;i<l;i++){
		if(s1[i]!=s2[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
