#include "bits/stdc++.h"
using namespace std;
const int N=2e5+5;
long long n,a,ans,cnt;
string s,d;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		cnt+=a;
		for(int i=1;i<=a;i++){
			if(s=="a"){
				d+="a";
			}else if(s=="b"){
				d+="b";
			}
			else if(s=="c"){
				d+="c";
			}
			else if(s=="d"){
				d+="d";
			}
			else if(s=="e"){
				d+="e";
			}
			else if(s=="f"){
				d+="f";
			}
			else if(s=="g"){
				d+="g";
			}
			else if(s=="h"){
				d+="h";
			}
			else if(s=="i"){
				d+="i";
			}
			else if(s=="j"){
				d+="j";
			}
			else if(s=="k"){
				d+="k";
			}
			else if(s=="l"){
				d+="l";
			}
			else if(s=="m"){
				d+="m";
			}
			else if(s=="n"){
				d+="n";
			}
			else if(s=="o"){
				d+="o";
			}
			else if(s=="p"){
				d+="p";
			}
			else if(s=="q"){
				d+="q";
			}
			else if(s=="r"){
				d+="r";
			}
			else if(s=="s"){
				d+="s";
			}
			else if(s=="t"){
				d+="t";
			}
			else if(s=="u"){
				d+="u";
			}
			else if(s=="v"){
				d+="v";
			}
			else if(s=="w"){
				d+="w";
			}
			else if(s=="x"){
				d+="x";
			}
			else if(s=="y"){
				d+="y";
			}
			else if(s=="z"){
				d+="z";
			}
		}
	}
	//cout<<cnt<<endl<<d<<endl;
	for(int i=0;i<cnt/2;i++){
		//cout<<i<<endl<<d[i]<<endl<<d[cnt-i-1]<<endl;
		if(d[i]!=d[cnt-i-1]){
			ans++;
			//cout<<i<<endl<<d[i]<<endl<<d[cnt-i-1]<<endl;
		}
	}
	cout<<ans;
	return 0;
}
