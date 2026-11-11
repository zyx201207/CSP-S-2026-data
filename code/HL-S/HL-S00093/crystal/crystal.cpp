#include<bits/stdc++.h>
using namespace std;
int n,m,ma,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=5000){	
	sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			int sum=0,s=1,j=i-1;
			while(j>=1){
				if(a[j]<=a[i]){
					if(sum+(a[i]-a[j])<=m){
						sum+=(a[i]-a[j]);
						s++;
					}
				}
				j--;
			}
			ma=max(ma,s);
		}
		printf("%d",ma);
	}
	else{
		int k=a[2]-a[1];
		int num=m/k;
		int i=1;
		while(num>=0){
			if(num>=i) num-=(i*k);
			i++;
		}
		printf("%d",i);
	}
	return 0;
}
