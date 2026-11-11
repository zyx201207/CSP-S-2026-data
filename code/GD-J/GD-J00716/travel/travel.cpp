#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b){
		if(c[0]==d[0] and c[1]==d[1]){
			if(((c[2]=='A' or c[2]=='B' or c[2]=='C') and (d[2]=='A' or d[2]=='B' or d[2]=='C')) or ((c[2]=='D' or c[2]=='E' and d[2]=='D' or d[2]=='E'))){
				if(c[2]+1==d[2] or c[2]-1==d[2]){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else{
				cout<<"1100";
			}
		}

		else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0; 
}
