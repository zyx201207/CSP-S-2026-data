#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin,(x).end
#define fi first
#define se second
#define pb push_back


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	} 
	cout<<1;
	if(b[1]!=d[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(b[2]<='C'&&d[2]>'C'||b[2]>'C'&&d[2]<='C'){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(b[2]=='C'&&d[2]=='A'||b[2]=='A'&&d[2]=='C'){
	    cout<<"0";
	    return 0;
	}
	cout<<1;
	return 0;
}


































































































































































































