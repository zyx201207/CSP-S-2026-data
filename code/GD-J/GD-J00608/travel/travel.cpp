#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
string a,b,x,y;
string pp1[6]={"AB","AC","BA","BC","CA","CB"};
string pp2[2]={"EF","FE"};
string tt1[4]={"AB","BA","BC","CB"};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>x>>y;
	if(a!=x){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		int ux=0,uy=0;
		for(int i = 0;i<2;i++){
			ux=ux*10+int(b[i]-'0');
			uy=uy*10+int(y[i]-'0');
		}
		if(ux!=uy){
			cout<<"000";
			return 0;
		}else{
			cout<<1;
			bool flag1=0,flag2=0;
			string t="  ";
			t[0]=b[2],t[1]=y[2];
//				cout<<t<<"\n";
			for(int i = 0;i<6;i++){
				if(pp1[i]==t) flag1=1;
			}
			for(int i = 0;i<2;i++){
				if(pp2[i]==t) flag2=1;
			}
			if(flag1==0&&flag2==0){
				cout<<"00";
				return 0;
			}else{
				cout<<1;
				bool flag11=0,flag22=0;
				for(int i = 0;i<4;i++){
					if(tt1[i]==t) flag11=1;
				}
				for(int i = 0;i<2;i++){
					if(pp2[i]==t) flag22=1;
				}
				if(flag11==0&&flag22==0){
					cout<<0;
					return 0;
				}else{
					cout<<1;
					return 0;
				}
			}
		}
	}
	return 0; 
} 
