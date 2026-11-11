#include<bits/stdc++.h>
using namespace std;
int t,n;
long long sum=1,ans=0;
char word;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,&word);
		for(int i=sum;i<=sum+n;i++){
			a[i]=word;
		}
		sum+=n;
	}
	for(int i=1,j=sum;i<=sum/2,j>=sum-(sum/2)+1;i++,j--){
		if(a[i]!=a[j]) ans++;
	}
	printf("%lld",ans);
	return 0;
} 
