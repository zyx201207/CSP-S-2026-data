#include<bits/stdc++.h>
using namespace std;
int mm,n,m,a[500005],ans=1,s[50005],z,ma;
int main(){
	freopen("crystal2.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	mm=m;
	sort(a+1,a+n+1);
	for(int k=1;k<=n;k++){
		z=a[k],ans=1,m=mm;
		for(int i=k-1;i>=1;i--){
			if(abs(z-a[i])<=m){
				m-=abs(z-a[i]);
				ans++;
			}
		}
		ma=max(ans,ma);
	}
	cout<<ma;
	return 0;
} 
