#include<bits/stdc++.h>
using namespace std;
string sa,sa2,sb,sb2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa>>sa2>>sb>>sb2;
	sa+=sa2;
	sb+=sb2;
	if(sa[0]==sb[0]&&sa[1]==sb[1]){
		cout<<"1";
		if(sa[2]==sb[2]&&sa[3]==sb[3]){
			cout<<"1";
			if((sa[4]>='D')==(sb[4]>='D')){
				cout<<"1";
				if(max((int)sa[4]-sb[4],(int)sb[4]-sa[4])==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}