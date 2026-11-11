#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k;
    scanf("%d %d",&c,&t);
    vector<int>v(n-1,0),u(n-1,0);
    while(t--){
    	long long a=0;
    	for(int i=0;i<n-1;i++){
    		scanf("%d %d",&v[i],&u[i]);
    		a+=v[i]+u[i];
		}
		a/=n;
		printf("%lld",a);
	}
	return 0;
}

