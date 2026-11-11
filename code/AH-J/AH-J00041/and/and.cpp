#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N][35],ans;
bool pd[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x,s=0;
		scanf("%d",&x);
		while(x){
			a[i][s]=x&1;
			x>>=1,s++;
		}
	}
	for(int i=30;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]==1&&!pd[j]) sum++;
		}
		if(sum>=m){
			ans+=1<<i;
			for(int j=1;j<=n;j++){
				if(a[j][i]==0) pd[j]=true;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
