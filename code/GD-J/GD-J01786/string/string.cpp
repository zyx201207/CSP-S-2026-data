#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int x,ans;
	cin>>x;
	string S,s,tt;
	for(int i=0,t;i<x;i++){
		cin>>t>>s;
		while(t--){
			S+=s;
			tt=s+tt;
		}
	}for(int i=0;i<S.length();i++){
		if(S[i]!=tt[i])ans++;
	}cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
}
