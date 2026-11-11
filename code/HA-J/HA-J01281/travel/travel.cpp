#include<bits/stdc++.h>
using namespace std;
string cc1,cc2;
char ss11,ss12,ss13,ss21,ss22,ss23; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>cc1>>ss11>>ss12>>ss13>>cc2>>ss21>>ss22>>ss23;
	if(cc1==cc2){
		if(ss11==ss21 && ss12==ss22){
			if((ss13=='C' && ss23=='D') || (ss13=='D' && ss23=='C')){
				cout<<"1100";
			}
			else{
				if(ss13==ss23+1 || ss13==ss23-1){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
