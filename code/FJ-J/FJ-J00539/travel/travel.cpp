#include<bits/stdc++.h>

using namespace std;
string c1,c2;
char ans[4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("treval.out","w",stdout);
	cin>>c1;
	int a,b;
	char n,m;
	cin>>a>>n;
	cin>>c2;
	cin>>b>>m;
	ans[0]=ans[1]=ans[2]=ans[3]='0';
	if(c1==c2){
		ans[0]='1';
	}
	else{
		ans[0]='0';
		ans[1]='0';
		ans[2]='0';
		ans[3]='0';
		cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
		return 0;
	}
	if(a==b){
		ans[1]='1';
		if((n+1==m||n-1==m)&&!(n=='D'&&m=='C')&&!(n=='C'&&m=='D'))ans[3]='1';
		if((n>='A'&&n<='C'&&m>='A'&&m<='C')||((n=='D'&&m=='F')||(n=='F'&&m=='D'))){
			ans[2]='1';
		}
	}else{
		ans[1]='0';
		ans[2]='0';
		if(n==m&&(a+1==b||a-1==b)){
			ans[3]='1';
		}
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
