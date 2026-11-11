#include<bits/stdc++.h>
using namespace std;
int n,ans,mi=200000000,tu,a[200005];
char k[27];
bool b[27];
long long l[27];
string s="";
int min(int a,int b){
	if(a>b) return b;
	return a;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<26;i++){
		char b1='a'+i;
		k[i]=b1;
	} 
	for(int i=0;i<n;i++){
			int a;
			char c;
			cin>>a>>c;
			for(int i=0;i<26;i++){
				if(c==k[i] && b[i]==0){
					tu++;
					b[i]=1;
					l[i]+=a;
				}
			}
			for(int i=1;i<=a;i++){
				s+=c;
			}
		}
		if(tu==1) {
			cout<<0;
			return 0;
		}
		if(tu==2){
			for(int i=0;i<26;i++){
				if(!l[i]){
					mi=min(mi,l[i]);
				}
			}
		cout<<mi;
		return 0;
	}
	if(n<=2){
		for(int i=0;i<n;i++){
			int a1;
			char c1;
			cin>>a1>>c1;
			mi=min(mi,a1);
		}
		cout<<mi;
		return 0;
	}
	else{
		for(int i=0;i<s.size();i++){
			int t=s.size()-1-i;
			if(i>=t) {
				cout<<ans;
				break;
			}
			if(s[i]!=s[t]) ans++;
			else continue;
		}
	}

	return 0;
}
