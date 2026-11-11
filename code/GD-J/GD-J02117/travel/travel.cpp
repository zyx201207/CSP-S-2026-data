#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int res1=0,res2=0;
int ans[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans[1]=1;
	else{
		for(int i=1;i<=4;i++) cout<<0;
		return 0;
	}
	
	for(int i=0;i<=1;i++){
		res1=res1*10+(int)(s1[i]-'0');
		res2=res2*10+(int)(s2[i]-'0');
	}
	if(res1==res2) ans[2]=1;
	else{
		for(int i=2;i<=4;i++) ans[i]=0;
		for(int i=1;i<=4;i++) cout<<ans[i];
		return 0; 
	}
	
	char a=s1[2];
	char b=s2[2];
	if((a>='A' && a<='C' && b>='D' && b<='F') || (a>='D' && a<='F' && b>='A' && b<='C')){
//		cout<<a<<' '<<b<<'\n';
		for(int i=3;i<=4;i++) ans[i]=0;
		for(int i=1;i<=4;i++) cout<<ans[i];
		return 0;
	}
	else{
		if(a>='A' && a<='C' && b>='A' && b<='C'){
			int p=(int)(a-'A')-(int)(b-'A');
			if(abs(p)==1){
				for(int i=1;i<=4;i++) cout<<1;
				return 0;
			}
		}
		if((a=='D' && b=='F') || (a=='F' && b=='D')){
			for(int i=1;i<=4;i++) cout<<1;
			return 0;
		}
	}
	ans[3]=1;
	for(int i=1;i<=4;i++) cout<<ans[i];
	return 0;
}
/*
02 01A 02 01B

02 01C 02 01A

Trick||Treat!
*/
