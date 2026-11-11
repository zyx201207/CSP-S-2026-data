#include<bits/stdc++.h>//CCF is gay -J出的啥啊拉了 
//#define DEBUG 1
//#define DLOG 1
//#ifdef DEBUG
//	#ifdef DLOG
//		#define log cerr
//	#else
//		#define log cout
//	#endif
//#else
//	#define DEBUG 0
//	#define DLOG 0
//	#define log 0&&cout
//#endif
//#define ifdb if(DEBUG)
using namespace std;
using ll=long long;
using i128=__int128;
ll c1,c2,p1,p2;
char h1,h2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	freopen(".ky","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	p1=(s1[0]-'0')*10+(s1[1]-'0');
	p2=(s2[0]-'0')*10+(s2[1]-'0');
	h1=s1[2];
	h2=s2[2];
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	if(p1!=p2){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}
	if((min(h1,h2)<='C')&&(max(h1,h2)>='D')){
		cout<<"00";
		return 0;
	}else{
		cout<<"1";
	}
	if((max(h1,h2)-min(h1,h2)!=1)||(max(h1,h2)=='F'&&min(h1,h2)=='D')){
		cout<<"0";
		return 0;
	}else{
		cout<<"1";
	}
	return 0;
}
