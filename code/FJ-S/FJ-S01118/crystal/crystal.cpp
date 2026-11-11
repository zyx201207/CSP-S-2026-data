#include<bits/stdc++.h>
using namespace std;
long long n,m,t,cnt,a[500005],b[500005];
bool c=1;
void dfs(int k,int p){
	if(p==n) return;
	if(k<m){
		for(int i=0;i<n;i++) b[i]=a[i];
		t=0;
		while(c){
			c=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if(b[i]==b[j]&&b[i]!=1000000000001){
						c=1;
						t++;
						b[i]=1000000000001;
						b[j]*=2;
					}
				}
			}
		}
		cnt=max(cnt,t);
	}
	if(k==m-1) return;
	for(int i=0;i<n;i++){
		a[i]++;
		dfs(k+1,p+1);
		a[i]--;
		dfs(k,p+1);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,0);
	printf("%lld",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
