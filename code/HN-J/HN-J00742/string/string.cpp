#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int o;
	string p;
	for(int i=1;i<=n;i++){
		cin>>o>>p;
		for(int j=1;j<=o;j++){
			s+=p;
		}
	}
	string op="";
	for(int i=s.size()-1;i>=0;i--){
		op+=s[i];
	}
	if(op==s) cout<<"0";
	else{
		for(int i=0;i<s.size();i++){
			if(op[i]!=s[i]) ans++;
		}
	    cout<<ans/2;	
    }
    //aabbc cbbaa
	return 0;
}
/*
a[100005]
for(int i=1;i<=n/2;i++)
if(a[i]!=a[n-i+1]){
if(b[i]!=b[n-i+1]) ans+=min(b[i],b[n-i+1]); o[0||1]=max()-min();
if(n-i+1=i+1) zhouweilianggeshifouxiangdeng xiangdeng,zongshuchuerjisuanbutongzongshuchuer
*/
