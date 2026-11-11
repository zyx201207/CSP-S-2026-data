#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int er[N][31],a[N];
int cnt;
void zh(int n){
	for(int i=0;i<n;i++){
		int x=a[i];
		while(x){
			er[i][cnt++]=x%2;
			x/=2;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	zh(n);
	int ans=a[0];
	if(m==n){
		for(int i=1;i<n;i++)
			ans=ans&a[i];
		printf("%d",ans);
		return 0;
	}
	if(m==1){
		printf("%d",a[n-1]);
		return 0;
	}
	
	return 0;
}
