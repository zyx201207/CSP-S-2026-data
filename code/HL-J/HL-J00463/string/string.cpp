#include<bits/stdc++.h>
using namespace std;
int n,m,x,cnt=-1,ans;
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>t;
		for(int j=1;j<=m;j++) s+=t;
	}x=s.size();
	if(x%2==0){
		m=x/2;
		for(int i=m;i<x;i++){
			cnt+=2;
			if(s[i]!=s[i-cnt]) ans++;
		}
	}else{
		m=x/2+1;
		cnt=0;
		for(int i=m;i<x;i++){
			cnt+=2;
			if(s[i]!=s[i-cnt]) ans++;
		}
	}cout<<ans;
}


