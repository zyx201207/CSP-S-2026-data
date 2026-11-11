#include<bits/stdc++.h>
using namespace std;
//#define int long long
string n,m;
string r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>r>>m>>x;
	if(n==m){
		cout<<1;
	}else{
		cout<<0;
	}
	if(n==m&&r[0]==x[0]&&r[1]==x[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(n==m&&r[0]==x[0]&&r[1]==x[1]&&((r[2]>='A'&&r[2]<='C'&&x[2]>='A'&&x[2]<='C')||(r[2]>='D'&&r[2]<='F'&&x[2]>='D'&&x[2]<='F'))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(n==m&&r[0]==x[0]&&r[1]==x[1]&&((r[2]>='A'&&r[2]<='C'&&x[2]>='A'&&x[2]<='C')||(r[2]>='D'&&r[2]<='F'&&x[2]>='D'&&x[2]<='F'))&&abs(r[2]-x[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
