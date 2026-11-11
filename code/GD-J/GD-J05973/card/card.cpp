#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int z,x,c,v=-1,b=0;
	cin>>z>>x;
	for(int i=1;i<=z;i++){
		cin>>c;
		if(c!=v&&i!=1)cout<<i-1;
		v=c;
	}
    return 0;
}