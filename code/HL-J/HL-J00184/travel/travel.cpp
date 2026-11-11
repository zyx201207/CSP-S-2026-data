#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int a,c,B,D;
	char b[5],d[5];
	cin>>a;
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	cin>>c;
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	B=(int)b[3];
	D=(int)d[3];
	if(a==c){
		cout<<'1';
		if(b[1]==d[1]&&b[2]==d[2]){
			cout<<'1';
			if(B<67&&B+1==D||D<67&&D+1==B||B<67&&B+2==D||D<67&&D+2==B||D==68&&B==70||B==68&&D==70){
				cout<<'1';
				if(B+1==D||D+1==B)cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}