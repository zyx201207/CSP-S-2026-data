#include<bits/stdc++.h>
using namespace std;
#define int long long
int k[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,as,bs;
	cin>>a>>as>>b>>bs;
	//cout<<a<<as<<b<<bs;
	if(a==b){
		k[0]=1;
		if(as[0]==bs[0]&&as[1]==bs[1]){
			k[1]=1;
			int ta,tb,sf;
			ta=as[2]-'A'+1;
			tb=bs[2]-'A'+1;
			if((ta>3&&tb>3)||(ta<=3&&tb<=3)){
				k[2]=1;
				if(ta-tb==1||tb-ta==1){
					k[3]=1;
				}
			}
		}
	}
	cout<<k[0]<<k[1]<<k[2]<<k[3];
	return 0;
}
