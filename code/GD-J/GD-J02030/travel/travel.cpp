#include <bits/stdc++.h>//加freopen!!!!!!!!!!!
#define ll long long//加freopen!!!!!!!!!!!
using namespace std;//加freopen!!!!!!!!!!! 
string s1,s2,t1,t2;//加freopen!!!!!!!!!!!
int snum,tnum;//加freopen!!!!!!!!!!!
int main(){//加freopen!!!!!!!!!!!
	freopen("travel.in","r",stdin);//加freopen!!!!!!!!!!!
	freopen("travel.out","w",stdout);//加freopen!!!!!!!!!!!
	cin>>s1>>s2>>t1>>t2;//加freopen!!!!!!!!!!!
	snum=(s2[0]-'0')*10+(s2[1]-'0');//加freopen!!!!!!!!!!!
	tnum=(t2[0]-'0')*10+(t2[1]-'0');//加freopen!!!!!!!!!!!
	if(s1==t1){//加freopen!!!!!!!!!!!
		cout<<1;//加freopen!!!!!!!!!!!
		if(snum==tnum){//加freopen!!!!!!!!!!!
			cout<<1;//加freopen!!!!!!!!!!!
			if((s2[2]<='C')^(t2[2]<='C')==0){//加freopen!!!!!!!!!!!
				cout<<1;//加freopen!!!!!!!!!!!
				if(char(s2[2]+1)==t2[2] || char(t2[2]+1)==s2[2]){//加freopen!!!!!!!!!!!
					cout<<1;//加freopen!!!!!!!!!!!
				}else cout<<0;//加freopen!!!!!!!!!!!
			}else cout<<"00";//加freopen!!!!!!!!!!!
		}else cout<<"000";//加freopen!!!!!!!!!!!
	}else cout<<"0000";//加freopen!!!!!!!!!!!
	return 0;//加freopen!!!!!!!!!!!
}//加freopen!!!!!!!!!!!
/*

*/
