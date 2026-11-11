#include<bits/stdc++.h>
using namespace std;
int n,t,k,sum;
string s,d,sr,sz,st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>t>>d;
		for(int i=1;i<=t;i++)s=s+d;
	}
	k=s.size()/2;
	for(int i=0;i<k;i++)sz+=s[i];
	for(int i=s.size()-1;i>k;i--)st+=s[i];
	for(int i=0;i<k;i++){
		if(sz[i]!=st[i])sum++;
	}
	cout<<sum;
	return 0;
}
