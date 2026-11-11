#include<bits/stdc++.h>
using namespace std;
//a 小R车厢号 x 小R座位号
//b 小X车厢号 y 小X座位号
string a,b,x,y;
//ap 小R排号 bp 小R排号 
//az 小R座位 bz 小X座位
string ap,bp;
char az,bz;
bool tcx(){
	return a==b;
}
bool tp(){
	return ap==bp;
}
bool tc(){
	if(az>='A'&&az<='C'&&bz>='A'&&bz<='C'){
		return true;
	}else if(az>='D'&&az<='F'&&bz>='D'&&bz<='F'){
		return true;
	}else{
		return false;
	}
}
bool xl(){
	char u=az,v=bz;
	if(u>v) swap(u,v);
	return (u+1==v)&&!(u=='C'&&v=='D');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	 
	cin>>a>>x>>b>>y;
	ap=x.substr(0,2);az=x[2];
	bp=y.substr(0,2);bz=y[2];
	
//	cout<<ap<<' '<<bp<<' '<<az<<' '<<bz<<endl;
	int ans[4]={0,0,0,0};
	if(tcx()){ans[0]=1;
		if(tp()){ans[1]=1;
			if(tc()){ans[2]=1;
				if(xl()) ans[3]=1;
			}
		}
	}
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3]<<'\n';
	return 0;
} 
