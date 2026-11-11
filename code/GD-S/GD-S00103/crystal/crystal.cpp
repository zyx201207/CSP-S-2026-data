#include<bits/stdc++.h> 
using namespace std;
long long int n,m,a[100005],b[100005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if(a[i]>a[j]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	int ava,s=1;
	while(m>=0&&s<=n){
		ava=a[s+1]-a[s];
		if(m>=s*ava){
			ans++;
			m=m-s*ava;
		}
		else m=-1;
		s++;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
