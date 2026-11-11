#include<iostream>
#include<string>
using namespace std;
string c1,s1,c2,s2;
void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1!="01" && c1!="16" && c2!="01" && c2!="16"){
		if(c1==c2){
//			同一节车厢 
			cout<<1;
			if(s1[0]==s2[0] && s1[1]==s2[1]){
//				在同一节车厢的同一排
				cout<<1;
				char u=s1[2],v=s2[2];
				if((u<='C' && v<='C') || (u=='D' && v<='F') || (u=='F' && v<='D')){
//					同一节车厢的同一排，且位于过道的同一侧
					cout<<1;
					if((u=='A' && v=='B') || (u=='B' && v=='C') || (u=='D' &&v=='F') || (v=='A' && u=='B') || (v=='B' && u=='C') || (v=='D' &&u=='F')){
//						是否相邻
						cout<<1;
					}
					else{
						cout<<"0";
						return;
					}
					
				}
				else{
					cout<<"00";
					return;
				}
			}
			else{
				cout<<"000";
				return;
			}
		}
		else{
			cout<<"0000";
			return;
		}
	}
	else{
		cout<<"0000";
		return;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
}
//			cout<<"test";
