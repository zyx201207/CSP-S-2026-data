#include<bits/stdc++.h>
using namespace std;
int c,t,a[100005],b[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",c,t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n-1;i++){
			scanf("%d%d",&a[i],&b[i]);
		}
		printf("%d",a[c]*a[n/b[c]]/k*(t*t+c*c));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
