#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>c1 >>s1 >>c2 >>s2;
	char a1=s1[2],a2=s2[2];
	if(c1==c2){
		cout<<1;
		if(s1[1]==s2[1]){
			cout <<1;
			if(a1=='C' and a2=='D'){
				cout <<0 <<0;
			}
			else if(a1=='D' and a2=='C'){
				cout <<0 <<0;
			}
			else if(a1-a2>=3)cout <<0 <<0;
			else{
				cout <<1;
				if(a1-a2==1 or a2-a1==1){
					cout <<1;
				}
				else cout <<0;
			}
		}
		else cout <<0 <<0 <<0;
	}
	else cout <<0 <<0 <<0 <<0;
    return 0;
} 
