#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,f;
	scanf("%d%d",&n,&m);
	int a[500005];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int bes=0,all;
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		f=m;
		all=1;
		for(int j=i-1;j>=1;j--){
			int k=a[i]-a[j];
			if(f>=k){
				f=f-k;
				all++;
			}else{	
				break;
			}
		}
		bes=max(bes,all);
	}
	printf("%d",bes);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
