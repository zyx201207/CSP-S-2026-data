#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int l1[5],l2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<3;i++){
		l1[i]=s1[i]-'0';
		l2[i]=s2[i]-'0';
	}
	if(c1==c2){
		cout<<"1";
		if(l1[0]==l2[0] and l1[1]==l2[1]){
			cout<<"1";
			if(l1[2]<=19 and l2[2]<=19){
				cout<<"1";
				if(abs(l1[2]-l2[2])==1){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else if(l1[2]>19 and l2[2]>19){
				cout<<"11";
				return 0;
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
