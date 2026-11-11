#include<bits/stdc++.h>
using namespace std;
int n;
char c[200005];
long long a[200005],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1)continue;
		int j;
		for(j=i+1;c[j]==c[i];j++){
			if(a[j]==-1)continue;
			a[i]+=a[j];
			a[j]=-1;
		}
	}
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=-1)tmp++; 
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			for(int j=i+1;j<=n;j++){
				if(a[j]!=-1){
					a[i]=a[j];
					c[i]=c[j];
					a[j]=-1;
					break;
				}
			}
		}
	}
	n=tmp;
	int x=1,y=n;
	while(x<y){
		if(a[x]>a[y]){
			tmp=0;
			for(y;y>x;y--){
				tmp+=a[y];
				if(c[y]!=c[x])ans+=a[y];
				if(tmp>=a[x]){
					a[y]=tmp-a[x];
					ans-=a[y];
					break;
				}
			}
			x++; 
		}
		else{
			tmp=0;
			for(x;x<y;x++){
				tmp+=a[x];
				if(c[y]!=c[x])ans+=a[x];
				if(tmp>=a[y]){
					a[x]=tmp-a[y];
					ans-=a[x];
					break;
				}
			}
			y--;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
