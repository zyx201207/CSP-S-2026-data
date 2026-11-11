#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#define LL long long
const int N=1e5+10;
const int Inf=0x3f3f3f3f;
using namespace std;
string c1,st1,c2,st2;
string pai1,pai2;
bool vis[7][7]={{},{0,0,1,1},{0,1,0,1},{0,1,1,0},{0,0,0,0,0,0,1},{},{0,0,0,0,1}};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>st1>>c2>>st2;
	if(c1==c2){
		cout<<'1';
		for(int i=0;i<2;i++){
			pai1+=st1[i];
			pai2+=st2[i];
		}if(pai1==pai2){
			cout<<1;
			if(vis[st1[2]-'A'+1][st2[2]-'A'+1]==1){
				cout<<1;
				if((st1[2]-'A'+1==st2[2]-'A'||st1[2]-'A'-1==st2[2]-'A')&&(st1[2]!='D'&&st2[2]!='D')||(st1[2]=='F'&&st2[2]=='D')||(st2[2]=='F'&&st1[2]=='D')){
					cout<<1;
				}else cout<<0;
			}else{
				cout<<"00";
			}
		}else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}

