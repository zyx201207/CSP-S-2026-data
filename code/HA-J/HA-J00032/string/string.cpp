#include<bits/stdc++.h>
using namespace std;
char c[200002];
int n,a[200002],g;
map<char,int>mp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i]>>c[i];
		if(mp[c[i]]==0) g++;
		mp[c[i]]+=a[i];
	}
	if(n==1) cout<<0;
	else if(n==2){
		if(c[0]==c[1]) cout<<0;
		else cout<<min(a[0],a[1]);
	}else{
		char ch=c[0];
		bool f=true;
		for(int i=1;i<n;i++){
			if(ch!=c[i]){
				f=false;
				ch=c[i];
				break;
			}
		}
		if(f==true) cout<<0;
		if(g==2) cout<<min(mp[ch],mp[c[0]]);
	}
	return 0;
}
