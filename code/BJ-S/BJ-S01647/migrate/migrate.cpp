#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

int n,d;
int a[N];
int f[N];

void solve3(){
	
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cha=a[2]-a[1];
	if(cha*2<=d && cha*3>d ){
		solve3();
	}else{
		cout<<"0"<<'\n';
	}

}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
