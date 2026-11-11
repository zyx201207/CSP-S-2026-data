#include<bits/stdc++.h>
using namespace std;
#define int long long
string ch,cz,sh,sz;
int ac,bc,az,bz;
char a,b;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>ch>>cz>>sh>>sz;
	for(int i=0;i<ch.size();i++){
		ac=ac*10+(ch[i]-'0');
	}
	for(int i=0;i<sh.size();i++){
		bc=bc*10+(sh[i]-'0');
	}
	//cout<<ac<<' '<<bc<<"\n";
	if(ac!=bc){
		cout<<"0000";
		return 0;
	} 
	else cout<<1;
	for(int i=0;i<cz.size();i++){
		if(cz[i]>='0'&&cz[i]<='9'){
			az=az*10+(cz[i]-'0');
		}else{
			a=cz[i];
		}
	}
	for(int i=0;i<sz.size();i++){
		if(sz[i]>='0'&&sz[i]<='9'){
			bz=bz*10+(sz[i]-'0');
		}else{
			b=sz[i];
		}
	}
	//cout<<"\n"<<az<<" "<<a<<" "<<bz<<" "<<b<<"\n";
	if(az==bz) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='E'&&a<='F'&&b>='E'&&b<='F'))cout<<1;
	else{
		cout<<0;	
	} 
	int cha=abs(a-b);
	//cout<<cha;
	if(cha==1&&((a!='C'&&b!='D')&&(a!='D'&&b!='C'))) cout<<1;
	else cout<<0;

	return 0;
} 
