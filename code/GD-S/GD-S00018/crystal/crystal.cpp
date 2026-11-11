#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long p[500010];
bool check(int x,int y){
	if(abs((long long)(y*a[x]-(p[x-1]-p[x-y-1])))<=m){
		return true;
	}else{
		return false;
	}
}
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int mid=(l+r)>>1;
		while(l<r){
			mid=(l+r+1)>>1;
			if(check(i,mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,r);
	}
	cout<<ans+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
