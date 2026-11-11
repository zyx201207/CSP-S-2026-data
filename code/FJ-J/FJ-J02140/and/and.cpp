#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,q=-1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(q==-1) q = a[i];
		else q&=a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(m==1) printf("%d",a[1]);
	else if(m==n) printf("%d",q);
	else if(m==2){
		int h=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				h = max(h,(a[i]&a[j]));
			}
		}
		printf("%d",h);
	}
	else{
		int mm=0;
		for(int i=1;i<=n-m+1;i++){
			int p=a[i];
			for(int j=i+1;j<=n-m+2;j++){
				for(int k=j;k<=j+m-2;k++){
					p = p&a[k];
				}
				mm = max(mm,p);
			}
		}
		printf("%d",mm);
	}
	return 0;
}
