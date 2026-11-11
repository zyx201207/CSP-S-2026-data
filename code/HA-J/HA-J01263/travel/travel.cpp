#include<bits/stdc++.h>
using namespace std;
string tc1,tc2,ts1,ts2;
int main(int argc, char** argv) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>tc1>>ts1>>tc2>>ts2;
	if(tc1==tc2){
		cout<<'1'; 
		if(ts1[0]==ts2[0]&&ts1[1]==ts2[1]){
			cout<<'1';
			if((ts1[2]>67)==(ts2[2]>67)){
				cout<<'1';
				if(max(ts1[2],ts2[2])-1==min(ts1[2],ts2[2])&&max(ts1[2],ts2[2])!='D'){
					cout<<'1';
				}
				else{
					cout<<'0';
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
