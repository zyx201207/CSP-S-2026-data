#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,sx=0;
	cin>>n;
	string s="";
	for(int i=0;i<n;i++){
		int x;
		char op;
		cin>>x>>op;
		sx+=x;
		for(int j=0;j<x;j++)s+=op;
	}
	for(int i=0;i<sx/2;i++){
		if(s[i]!=s[sx-i-1])ans++;
	}
	cout<<ans<<endl;
//	cout<<sx<<endl;
//	cout<<n<<endl;
//	cout<<s;
	return 0;
}
