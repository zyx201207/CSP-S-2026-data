#include<bits/stdc++.h>
using namespace std;
int n,a,l,g;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		l+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	for(int i=0;i<=(l+1)/2;i++){
		if(s[i]!=s[l-i-1]){
			g++;
			s[l-i-1]=s[i];
		}
	}
	cout<<g;
	return 0;
}
