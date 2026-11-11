#include<bits/stdc++.h>
#define N 200010
#define INF 1e18
#define int long long
using namespace std;
int a,b;
string c,d,ans;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		ans+='1';
		if(c[0]==d[0]&&c[1]==d[1]){
			ans+='1';
			if(c[2]!='D'&&c[2]!='F'&&d[2]!='D'&&d[2]!='F'){
				ans+='1';
				if(c[2]=='B'||d[2]=='B')
				ans+='1';
			}if((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]=='F')){
				ans+="11";
			}
		}
	}
	cout<<ans;
	for(int i=ans.size()+1;i<=4;i++){
		cout<<0;
	}
	return 0;
}
