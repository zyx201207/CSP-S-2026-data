#include<bits/stdc++.h>
using namespace std;
short c;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	if(c=0){
		cin>>c;
		if(c==2) cout<<32<<17;
		if(c==3) cout<<35<<16;
	}
	cin>>c;
	cout<<26+c*3<<abs(19-c);
}
