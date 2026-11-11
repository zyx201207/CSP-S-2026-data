#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,c2,s1,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	
	ll a,b,x,y;
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	x=s1[2]-'A'+1;
	y=s2[2]-'A'+1;
	if(a==b && c1==c2){
		cout<<1;
		if(((1<=x && x<=3)&&(1<=y && y<=3)) || ((4<=x && x<=6)&&(4<=y && y<=6))){
			cout<<1;
		}else cout<<0;
	}
	else cout<<0<<0;
	if(a==b){
		if(x==1 && y==2) cout<<1;
		else if(x==2 && y==1) cout<<1;
		else if(x==2 && y==3) cout<<1;
		else if(x==3 && y==2) cout<<1;
		else if(x==4 && y==6) cout<<1;
		else if(x==6 && y==4) cout<<1;
		else cout<<0;
	}else cout<<0;
	return 0;
}
