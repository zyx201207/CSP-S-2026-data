#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin<<cr<<sr<<cx<<sx;

	if(cr == cx){
		cout <<1;
		if(sr[0] ==sx[0]&&sr[1]==sx[1]){
			cout<<1;
			if(sr[2] >='A'&&sr[2]<='C')&&(sx[2]>='A'&&sx[2]<='C'){
				cout<<1;
			}else{
				cout<<0;
			}else if(sr[2]=='D'||sr[2] == 'F'&&(sx[2]=='D'||sx[2] == 'F')){
				cout <<1<<1;
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0;
		}else{
			cout<<0<<0<<0;
			}
			else{
				cout<<0<<0<<0;
				}
	}


