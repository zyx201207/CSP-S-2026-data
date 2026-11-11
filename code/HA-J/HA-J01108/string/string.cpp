#include<bits/stdc++.h>
using namespace std;
string s;
int n,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int ai;
		char ci;
		cin>>ai>>ci;
		while(ai--) s+=ci;
	}
	int f1=0,f2=s.length()-1;
	while(f1<f2){
		if(s[f1]!=s[f2]) ans++;
		f1++;
		f2--;
	}
	cout<<ans;
	return 0;
}
