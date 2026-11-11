#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005]={};

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	

	
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=m;
		int num=1;
		for(int j=i-1;j>=1;j--){
			if(a[j]==a[i]) num++;
			else {
				if(a[i]-a[j]>x) break;
				else {
					x-=a[i]-a[j];
					num++;
				}
			}
		}
//		printf("%d\n",num);
		ans=max(num,ans);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
