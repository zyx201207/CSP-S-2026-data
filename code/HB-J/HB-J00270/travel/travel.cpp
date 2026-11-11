#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ca,cb,sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	
	if(ca==cb){
		cout<<1;
		if(sa[0]==sb[0] && sa[1]==sb[1]){
			cout<<1;
			char t=sa[2],tt=sb[2];
			if(('A'<=t && t<='C' && 'D'<=tt && tt<='F') || ('A'<=tt && tt<='C' && 'D'<=t && t<='F')){
				cout<<"00";
			}else{
				cout<<1;
				if((t-1)==tt || (t+1)==tt){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
//please RP++!!!
//luogu name is yidizzz !
//xiang jin mi huo xin wei da shang
//mai mai DX!
//X X XXX
//ilem is right!
//I can not speak English!!!
//RP++ qiu 1=
//bin bin bin
//freeopen
//freeopen
//freeopen
//freeopen
//freeopen
//freeopen
//T1-8:30~9:15 ?
//T2-9:15~10:20 ? bao li chu qi ji
//T3-10:20~11:15 ? da biao jin OI
//T4-10:20~11:42 zhi xie le xin zhi A
//gu gu gu
//198???,2=
//welcome to phigros!!!
//projekt_seikai is good!
//I like toya
//vbs!
//shi_nian_OI_yi_chang_kong
//bu_kai_long_long_jian_zu_zong
