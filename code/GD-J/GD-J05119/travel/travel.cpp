#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int sumb=0,suma=0,sumc=0,sumd=0;
	for(int i=0;i<=3;i++){
		if(b[i]>='0'&&b[i]<='9'){
			sumb*=10;
			sumb+=b[i]-'0';
		}
		if(a[i]>='0'&&a[i]<='9'){
			suma*=10;
			suma+=a[i]-'0';
		}
		if(c[i]>='0'&&c[i]<='9'){
			sumc*=10;
			sumc+=c[i]-'0';
		}
		if(d[i]>='0'&&d[i]<='9'){
			sumd*=10;
			sumd+=d[i]-'0';
		}
	}
	int ansr=b[2]-'A'+1;
	int ansx=d[2]-'A'+1;
	if(suma==sumc){
		cout<<1;
	}else{
		cout<<0;
	}
	if(suma==sumc&&sumb==sumd){
		cout<<1;
	}else{
		cout<<0;
	}
	if(suma==sumc&&sumb==sumd){
		if(ansr>=1&&ansr<=3&&ansx>=1&&ansx<=3){
			cout<<1;	
		}else if(ansr>=4&&ansr<=5&&ansx>=4&&ansx<=5){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(suma==sumc&&sumb==sumd){
		if(ansr==3&&ansx==4||ansr==4&&ansx==3){
			cout<<0;
		}else if(ansr+1==ansx||ansx+1==ansr){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
