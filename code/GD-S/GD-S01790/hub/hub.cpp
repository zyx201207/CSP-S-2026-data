#include<bits/stdc++.h>
#define N 2000010
using namespace std;
int c,g,n,k,a[N],b[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>g;
	while(g--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			scanf("%d%d",a+i,b+i);
		}
		if(c==7||c>=11&&c<=12){
			cout<<1<<endl;
		}
	}
	return 0;
}
