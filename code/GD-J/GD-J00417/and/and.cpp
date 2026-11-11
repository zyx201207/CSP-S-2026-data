#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
bool v[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=29;i>=0;i--){
		int k=1<<i;
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!v[j]&&(a[j]&k))++cnt;
		}
		if(cnt<m)continue;
		ans|=k;
		for(int j=1;j<=n;j++){
			if(!(v[j]||(a[j]&k)))v[j]=true;
		}
	}
	printf("%d",ans);
	return 0;
}
