#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N];
bool b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=29;~i;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!b[j]&&(a[j]&(1<<i))!=0){
				cnt++;
			}
		}
		if(cnt>=m){
			ans|=(1<<i);
			for(int j=1;j<=n;j++){
				if((a[j]&(1<<i))==0){
					b[j]=true;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}

