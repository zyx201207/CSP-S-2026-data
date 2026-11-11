#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005][31],last;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i][30]);
	last=n;
	for(int j=29;j>=0;j--){
		int cnt0=0,cnt1=0;
		for(int i=1;i<=last;i++){
			if((a[i][j+1]>>j)&1)cnt1++;
			else cnt0++;
		}
		if(cnt1>=m){
			ans+=(1<<j);
			int p=0;
			for(int i=1;i<=last;i++)
				if((a[i][j+1]>>j)&1)a[++p][j]=a[i][j+1];
			last=p;
		}else{
			int p=0;
			for(int i=1;i<=last;i++)
				a[++p][j]=a[i][j+1];
			last=p;
		}
	}
	printf("%d",ans);
	return 0;
}
