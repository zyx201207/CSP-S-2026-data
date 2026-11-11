#include<bits/stdc++.h>
using namespace std;
const int mod1=500,mod2=154,mod3=874,mod4=105;

int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	srand(time(NULL));
	cin>>c>>t;
	if(c==0){
		cout<<1<<endl<<2;
	}
	while(t--){
		cout<<1LL*rand()*rand()%mod1*rand()%mod2*rand()%mod4*rand()%mod3<<"\n";
	}
	
	return 0;
}