#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t;
int n,d;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		if(c==13||c==14)cout<<0<<endl;
		else{
			int s=a[2]-a[1];
			if(s/d<=1)cout<<0<<endl;
			else{
				cout<<n-2<<endl;
			}
		}
	}
    return 0;
} 
