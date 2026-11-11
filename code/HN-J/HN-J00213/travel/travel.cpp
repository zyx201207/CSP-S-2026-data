#include<bits/stdc++.h>
using namespace std;
string first,second;
int che1,che2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1>>first>>che2>>second;
	if(che1!=che2){
		cout<<"0000";
		return 0;
	}else{
		if(first[0]==second[0] && first[1]==second[1]){
			if((first[2]=='A' && second[2]=='B') or (first[2]=='B' && second[2]=='C') or (first[2]=='D' && second[2]=='F') or (first[2]=='B' && second[2]=='A') or (first[2]=='C' && second[2]=='B') or (first[2]=='F' && second[2]=='D')){
				cout<<"1111";
				return 0;
			}else if((first[2]=='A' && second[2]=='C') or (first[2]=='C' && second[2]=='A')){
				cout<<"1110";
				return 0;
			}else {
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";	
			return 0;
		}
	}
}
