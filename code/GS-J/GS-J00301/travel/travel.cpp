#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,a,b) for(ll i=a;i<=b;i++)
bool ans[5];
string a,b,c,d;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans[1]=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			ans[2]=1;
			if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')){
				ans[3]=1;
				if(abs(b[2]-d[2])==1)ans[4]=1;
			}
		}
	}
	fo(i,1,4)cout<<ans[i];
	return 0;
}//Trick||Treat!
