#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0,m=0,a[200005]={0},ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<(1<<n);i++){
		int num=0,sum=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				num++;
			}
		}
		if(num!=m) continue;
		int f=1;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				if(f){
					sum=a[j];
					f=0;
					continue;
				}
				sum=sum&a[j];
			}
		}
		if(sum>ans) ans=sum;
	}
	cout<<ans;
	
	return 0;
}
