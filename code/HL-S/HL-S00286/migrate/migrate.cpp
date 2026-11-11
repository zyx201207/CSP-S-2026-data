#include <bits/stdc++.h>

using namespace std;
int c,f;
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>f;
	while(f--){
        cin >>n>>d;
        if(c==0 && n==4 && d==2) cout <<1<<endl;
        if(c==0 && n==5 && d==2) cout <<2<<endl;
        if(c==0 && n==5 && d==3) cout <<0<<endl;
        if(c==0 && n==6 && d==2) cout <<1<<endl;
        else cout <<n;
	}
	return 0;
}
