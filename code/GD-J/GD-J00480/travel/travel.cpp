#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
char a[3]={'A','B','C'};
char b[2]={'D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		cout<<"1";
		if(sa[0]==sb[0]&&sa[1]==sb[1]){
			cout<<"1";
			int flagall=0;
			int flaga=0,flagb=0;
			for(int i=0;i<3;i++){
				if(sa[2]==a[i]){
					flaga=1;
				}
				if(sb[2]==a[i]){
					flagb=1;
				}
			}
			if(flaga&&flagb&&sa[2]!=sb[2]){
				cout<<"1";
				flagall=1;
			}
			flaga=0,flagb=0;
			for(int i=0;i<2;i++){
				if(sa[2]==b[i]){
					flaga=1;
				}
				if(sb[2]==b[i]){
					flagb=1;
				}
			}
			if(flaga&&flagb&&sa[2]!=sb[2]){
				cout<<"1";
				flagall=1;
			}
			if(!flagall){
				cout<<"00";
				return 0;
			}
			if(abs(sa[2]-sb[2])==1){
				cout<<"1";
				return 0;
			}else{
				cout<<"0";
				return 0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
