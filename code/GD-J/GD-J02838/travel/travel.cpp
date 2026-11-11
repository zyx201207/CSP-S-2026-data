#include<bits/stdc++.h>

//#define int ll
#define ll long long
#define pr pair<int,int>
#define mp make_pair
#define pb push_back

using namespace std;

char a[2],b[3],x[2],y[3];

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout); 
	cin>>a[0]>>a[1]>>b[0]>>b[1]>>b[2]>>x[0]>>x[1]>>y[0]>>y[1]>>y[2];
	if(a[0]==x[0]&&a[1]==x[1]) cout<<"1"; 
	else {cout<<"0000";return 0;}
	if(b[0]==y[0]&&b[1]==y[1]) cout<<"1";
	else {cout<<"000";return 0;}
	if((b[2]<='C'&&y[2]<='C')||(b[2]>='D'&&y[2]>='D')) cout<<"1"; 
	else {cout<<"00";return 0;}
	if(abs(b[2]-y[2])==1) cout<<"1";
	else {cout<<"0";return 0;}
	return 0;
}

