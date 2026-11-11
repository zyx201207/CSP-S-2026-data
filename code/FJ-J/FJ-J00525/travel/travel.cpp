#include<bits/stdc++.h>
using namespace std;

string ca,sa,cb,sb;
bool pd_1(char a,char b){
	if(a>b){
		swap(a,b);//保持a最小 
	}
	if(a=='D'&&b=='F') return true;
	if(a=='A'&&b=='B') return true;
	if(a=='A'&&b=='C') return true;
	if(a=='B'&&b=='C') return true;
	return false;
}
bool pd_2(char a,char b){
	if(a>b){
		swap(a,b);//保持a最小 
	}
	if(a=='D'&&b=='F') return true;
	if(a=='A'&&b=='B') return true;
	if(a=='B'&&b=='C') return true;
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		if(sa[0]==sb[0]&&sa[1]==sb[1]){
			if(pd_1(sa[2],sb[2])==true){
				if(pd_2(sa[2],sb[2])==true){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
