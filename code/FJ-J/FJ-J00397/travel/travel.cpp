#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ca,sa,cb,sb,ans;
	cin>>ca>>sa>>cb>>sb;
	if(ca!=cb){
		ans="0000";
	}
	else{
		string p,q;
		p=sa[0]+sa[1],q=sb[0]+sb[1];
		if(p!=q){
			ans="1000";
		}
		else{
			char a,b;
			a=sa[2],b=sb[2];
			if(((a>='A' && a<='C') && (b>='A' && b<='C')) || ((a>='D' && a<='F') && (b>='D' && b<='F'))){
				if((a>='A' && a<='C') && (b>='A' && b<='C')){
					if((a=='A' && b=='C') || (a=='C' && b=='A')){
						ans="1110";
					}
					else{
						ans="1111";
					}
				}
				else{
					ans="1111";
				}
			}
			else{
				ans="1100";
			}
		}
	}
	cout<<ans;
	return 0;
}
