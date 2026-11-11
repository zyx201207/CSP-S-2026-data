#include<bits/stdc++.h>
using namespace std;
string s;
long long a[2000];
char c[2000];
string rs;
int n,ans;
void to_reverse(string s,int l){
	for(int i=0,j=s.size();i<l,j>l;i++,j--){
		if(s[j]!=s[i]){
			ans++;
		}
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	int l=s.size();
	if(s.size()%2==0)	l/=2;
	else l=(l/2)+1;
	rs=s;
	reverse(rs.begin(),rs.end());
	if(rs==s){
		cout<<0;
		return 0;
	}
	else{
		to_reverse(s,l);
	}
	return 0;
}
