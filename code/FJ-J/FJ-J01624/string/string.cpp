#include<bits/stdc++.h>
using namespace std;//68
int n,a,ans;char c;string f,f1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)f+=c;
	}
	f1=f;
	reverse(f1.begin(),f1.end());
	int st=f1.size();
	if(st%2==0)st/=2;
	else st=st/2+1;
	
	for(int i=0;i<st;i++){
		if(f[i]!=f1[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
