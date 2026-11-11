#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[1]=1;
	}if(b[0]==d[0]&&b[1]==d[1]&&ans[1]){
		ans[2]=1;
	}if(b[2]<='C'&&d[2]<='C'&&ans[2]){
		ans[3]=1;
	}if(b[2]>'C'&&d[2]>'C'&&ans[2]){
		ans[3]=1;
	}int x=b[2],y=d[2];
	if(abs(x-y)==1&&ans[3]) ans[4]=1;
	for(int i=1;i<=4;i++) cout<<ans[i];
	return 0;
}
