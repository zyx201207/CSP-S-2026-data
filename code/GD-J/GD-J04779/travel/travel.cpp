#include<bits/stdc++.h>
using namespace std;
string cxa,cxb;
string zwa,zwb;
void solve(){
	if(zwa[0]==zwb[0]&&zwa[1]==zwb[1]){
		cout<<1;
		if((zwa[2]<='C'&&zwb[2]<='C')||(zwa[2]=='F'&&zwb[2]=='D')||(zwa[2]=='D'&&zwb[2]=='F')){
			cout<<1;
			if((zwa[2]=='F'&&zwb[2]=='D')||(zwa[2]=='D'&&zwb[2]=='F')){
				cout<<1;
			}else{
				if(zwa[2]<='C'&&zwa[2]>='A'&&zwb[2]<='C'&&zwb[2]>='A'){
					char c=zwa[2];
					char ch=zwb[2];
					if(c>ch){
						swap(c,ch);
					}
					if(c+1==ch){
						cout<<1;
					}else{
						cout<<0;
					}
				}
			}
		}
		else{
			cout<<0;
			cout<<0;
		}
		
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
	}
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cxa>>zwa;
	cin>>cxb>>zwb;
	if(cxa==cxb){
		cout<<1;
		solve();
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
