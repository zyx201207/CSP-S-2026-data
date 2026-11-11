//GZ-J00565 ¡∫∫È»Ò 
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
void solve(){
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a!=b){
		cout<<"0000\n";
		return;
	}
	cout<<1;
	if(c[0]+c[1]==d[0]+d[1]){
		cout<<1;
	}else{
		cout<<"000\n";
		return;
	}
	if((c[2]<='C'&&d[2]<='C')||(c[2]>='D'&&d[2]>='D')){
		cout<<1;
	}else{
		cout<<"00\n";
		return;
	}
	if((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='C')||(c[2]=='D'&&d[2]=='F')||(c[2]=='B'&&d[2]=='A')||(c[2]=='C'&&d[2]=='B')||(c[2]=='F'&&d[2]=='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
