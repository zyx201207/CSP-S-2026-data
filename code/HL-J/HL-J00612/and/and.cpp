#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int a[200001]={};
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int ans=a[n-1];
	for(int i=n-1;i>=n-m;i--){
		ans&=a[i];
		printf("%d ",ans);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout); 
    return 0;
}

