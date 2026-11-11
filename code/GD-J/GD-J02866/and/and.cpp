#include<bits/stdc++.h> 
using namespace std;
int n,m,a[300000],amax,cnt,maxa;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		cnt=1;
		maxa=a[i];
		for(int j=i+1;j<=n;j++){
			if(cnt==m) break;
			maxa&=a[j];
			cnt++;
		}
		amax=max(amax,maxa);
	}
	printf("%d",amax);
	return 0;
}
