#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool f1=0,f2=0,f3=0,f4=0;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		f1=1;
	}
	if(f1==1&&c2[0]==c4[0]&&c2[1]==c4[1]){
		f2=1;
	}
	if(f2==1&&((c2[2]<='C'&&c4[2]<='C')||(c2[2]>='D'&&c4[2]>='D'))){
		f3=1;
	}
	if(f3==1&&((c2[2]>='D'&&c4[2]>='D')||(int(c2[2]-c4[2])==1||int(c2[2]-c4[2])==-1))){
		f4=1;
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
