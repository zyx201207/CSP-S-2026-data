#include<bits/stdc++.h> 
using namespace std;

int n,m,a[200200],ans=-1;//Cici

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		int cnt=a[i];
		for(int j=i+1;j<(n-m+1);j++){
			for(int k=j;k<(j+m-1);k++){
				cnt&=a[k];
				ans=max(ans,cnt);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
