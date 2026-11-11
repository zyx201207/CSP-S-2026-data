#include<cstdio>
const int MAXN=2e5+5;
int n;
int a[MAXN];
char ch[MAXN]; 
long long ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&ch[i]);
	}
	int i=1,j=n;
	while(i<=j){
		if(ch[i]!=ch[j]){
			if(a[i]==a[j]){
				ans+=a[i];
				i++;
				j--;
			}else if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}else{
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
		}else{
			if(a[i]==a[j]){
				i++;
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				a[i]-=a[j];
				j--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
