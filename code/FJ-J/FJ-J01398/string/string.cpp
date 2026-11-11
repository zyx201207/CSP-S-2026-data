#include<bits/stdc++.h>
using namespace std;
int n,arr[200005][2];
char c[200005][2];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&arr[i][0],&c[i][0]);
		arr[n-i+1][1]=arr[i][0];
		c[n-i+1][1]=c[i][0];
	}
	int ff=arr[1][0],ee=arr[1][1];
	for(int i=1,j=1;i<=n&&j<=n;){
		int w=0;
		if(c[i][0]!=c[j][1]){
			w=1;
		}
		if(ff==ee){
			ans+=ff*w;
			i++;
			j++;
			ff=arr[i][0];
			ee=arr[j][1];
		}else if(ff<ee){
			ans+=ff*w;
			i++;
			ee-=ff;
			ff=arr[i][0];
		}else{
			ans+=ee*w;
			j++;
			ff-=ee;
			ee=arr[j][1];
		}
	}
	printf("%lld",ans/2);
	return 0;
}
