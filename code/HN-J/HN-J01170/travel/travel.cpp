#include<bits/stdc++.h>
using namespace std;
string a1,sa,b1,sb;
int f=4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>sa>>b1>>sb;
	if(a1==b1){
		cout<<1;
		f--;
		if(sa[0]==sb[0]&&sb[1]==sa[1]){
			cout<<1;
			f--;
			if(((sa[2]=='A'||sa[2]=='B'||sa[2]=='C')&&(sb[2]=='A'||sb[2]=='B'||sb[2]=='C'))||((sa[2]=='D'||sa[2]=='E')&&(sb[2]=='D'||sb[2]=='E'))){
				cout<<1;
				f--;
				if(sa[2]-1==sb[2]||sa[2]+1==sb[2]){
					cout<<1;
					f--;
				}
			}
		}
	}
	while(f){
		cout<<0;
		f--;
	}
	return 0;
}
