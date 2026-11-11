#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int N,ASum=0,ans=0,minn,a[maxn];
char b[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&a[i]),cin>>b[i],ASum+=a[i];
	for(int i=1,j=N;i<j;){
		minn=min(a[i],a[j]);
		a[i]-=minn,a[j]-=minn;
		if (b[i]!=b[j])
			ans+=minn;
		if (a[i]==0)
			i++;
		if (a[j]==0)
			j--;
	}
	printf("%d",ans);
	return 0;
}
