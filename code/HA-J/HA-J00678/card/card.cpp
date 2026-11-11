#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=6e5;
int n,m,o,x,a[N],ans[N],f[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i-1]>a[i]) o=1;
		ans[a[i]]=max(ans[a[i]],i);
	}
	if(o){
		for(int i=1;i<=m;i++)
			ans[i]=0;
		f[a[n]]=1;ans[a[n]]=n;
		for(int i=n-1;i>=1;i--){
			int j=i-1,_=1;
			while(!f[a[j]]&&j>0)
				++_,--j;
			f[a[i]]=1;
			ans[a[i]]=max(ans[a[i]],_);
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}

