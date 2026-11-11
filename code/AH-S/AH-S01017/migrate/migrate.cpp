#include <bits/stdc++.h>
using namespace std;
int c;
int n,d;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int x=a[2]-a[1];
			if(!((n-1)%x)){
				cout<<1;
				continue;
			} 
		}
	}
	return 0;
}

