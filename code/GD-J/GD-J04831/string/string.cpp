#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,hui[214514],len,l[214514],r[214514],bianli,answ;
char zifu[214514];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;bianli=n;
	for(int i=1;i<=n;i++){
		cin>>hui[i]>>zifu[i];
		len+=hui[i];
		l[i]=r[i-1]+1;r[i]=l[i]+hui[i]-1;
	}
	for(int i=1;l[i]<=len/2;i++){
		int adao=len-min(r[i],len/2)+1,bdao=len-l[i]+1;
		for(int j=bdao;j>=adao;j--){
			int tou=j;
			j=max(l[bianli],adao);
			if(zifu[bianli]!=zifu[i]){
				answ+=tou-j+1;
			}if(j==l[bianli])bianli--;
			if(j==adao)break;
		}
	}cout<<answ<<'\n';
	return 0;
}
