#include <bits/stdc++.h>
using namespace std;
#define int long long
char c,f;
int a,b,d,e;
int ans[40];

bool lei(char x){
	if(x <= 'C') return true;
	return false; 
}

void sol(){
	if(a != d) return;
	ans[1] = 1;
	if(b != e) return;
	ans[2] = 1;
	if(lei(c) == lei(f)) ans[3] = 1;
	else return;
	if(abs(c-f) == 1) ans[4] = 1;
} 

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>b>>c>>d>>e>>f;
	sol();
	for(int i = 1; i <= 4; i++) cout<<ans[i];
	return 0;
}
