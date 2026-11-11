//GZ-J00224 Í¿Ðù½Ü 
#include<bits/stdc++.h>
using namespace std;
string r(string s){
	string an;
	for(int i=s.size()-1;i>=0;i--)an+=s[i];
	return an;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	string a,b,c;
	cin>>n; 
	for(int i=0;i<n;i++){
		int c;
		char s;
		cin>>c>>s;
		for(int j=0;j<c;j++)a+=s;
	}
	for(int i=0;i<a.size()/2;i++)b+=a[i];
	int p=0;
	if(a.size()%2==1)p=1;
	for(int i=a.size()/2+p;i<a.size();i++)c+=a[i];
	c=r(c);
	if(b==c)ans=0;
	else for(int i=0;i<b.size();i++)if(b[i]!=c[i])ans++;
	cout << ans<<endl;
	return 0;
}
