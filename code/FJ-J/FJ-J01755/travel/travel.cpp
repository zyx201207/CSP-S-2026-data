#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
string ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	int rn=0,xn=0;
	for(int i=0;i<2;++i){
		rn*=10;
		rn+=rs[i]-'0';
		xn*=10;
		xn+=xs[i]-'0';
	}
	if(rc!=xc) ans="0000";
	else{
		ans+='1';
		if(rn==xn){//Í¬ÅÅ 
			ans+='1';
			if(rs[2]<='C'&&xs[2]<='C'||rs[2]>'C'&&xs[2]>'C'){//Í¬²à 
				ans+='1';
				if(rs[2]+1==xs[2]||xs[2]+1==rs[2]){
					ans+='1';
				}
				else{
					ans+='0';
				}
			}
			else{
				ans+="00";
			}		
		}
		else{
			ans+="00";
			if(abs(rn-xn)==1&&rs[2]==xs[2]){
				ans+='1';
			}
			else{
				ans+='0';
			}
		}
	}  
	cout<<ans<<'\n';
	return 0;
}
