#include<bits/stdc++.h>
using namespace std;
string sa,sb,aa,ab;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa>>aa>>sb>>ab;
	if(sa==sb){
		cout<<1;
		if(aa[0]==ab[0] and aa[1]==ab[1]){
			cout<<1;
			if(aa[2]<'D' and ab[2]<'D'){
				cout<<1;
				char a=aa[2],b=ab[2];
				if((a=='A'&&b=='B') || (a=='B'&&b=='A') || (a=='B'&&b=='C') || (a=='C'&&b=='B') || (a=='D'&&b=='f') || (a=='F'&&b=='D')) cout<<1; //4
				else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
