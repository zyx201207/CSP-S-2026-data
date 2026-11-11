#include<bits/stdc++.h>
using namespace std;
int a[200005][2],n,b[2000005];
char tmp;
long long cnt,mid,gb,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i][0],&tmp);
		a[i][1]=tmp;
		cnt+=a[i][0];
	}
	for(int i=0;i<cnt;i++){
		for(int j=0;j<a[i][0];j++){
			b[gb]=a[i][1];
			gb++;
		}
	}
	if(cnt%2==0){
		mid=cnt/2;
	}else{
		mid=(cnt-1)/2+1;
	}
	for(int i=0;i<mid;i++){
		if(b[i]!=b[cnt-i-1]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
