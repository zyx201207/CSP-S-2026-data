#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
typedef long long ll;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<1;
    if(b.substr(0,2)!=d.substr(0,2)){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='F')){
		cout<<"00";
		return 0;
	}
	if((d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='D'||b[2]=='F')){
		cout<<"00";
		return 0;
	}
    cout<<1;
    if(abs(int(b[2])-int(d[2]))!=1){
	   cout<<0;
	   return 0;
    }
    cout<<1;
    return 0;
}
