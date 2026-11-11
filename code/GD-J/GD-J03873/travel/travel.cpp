#include<bits/stdc++.h>

using namespace std;

string a,b,c,d;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&(max(b[2],d[2])<='C'||min(b[2],d[2])>='D')){
		cout<<1;
	}
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&(max(b[2],d[2])<='C'||min(b[2],d[2])>='D')&&max(b[2],d[2])-min(b[2],d[2])==1&&max(b[2],d[2])!='D'){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
