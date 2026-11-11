#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,d;
	cin>>n>>d;
	vector<int>a(2000005);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]-a[j]==3)cout<<1;
			if(a[i]-a[j]==4)cout<<2;
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	
} 
