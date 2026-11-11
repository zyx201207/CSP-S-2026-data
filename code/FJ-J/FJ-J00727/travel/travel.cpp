#include<bits/stdc++.h>
#define ll long long
#define FOR(x,y,z) for(int x=y;x<=z;x++)
#define ROF(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
string c1,s1,c2,s2;
ll a,b,x,y,n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(c1[0]-'0')*10+(c1[1]-'0');
	b=(c2[0]-'0')*10+(c2[1]-'0');
	x=(s1[0]-'0')*10+(s1[1]-'0');
	y=(s2[0]-'0')*10+(s2[1]-'0');
	if(a==b){
		cout<<1;
		if(x==y){
			cout<<1;
			if((s1[2]<='C')==(s2[2]<='C')){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
