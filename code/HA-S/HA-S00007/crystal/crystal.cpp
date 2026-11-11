#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long b[500010];
const long long MAXX=1000000000000;
int ans=1;
bool pd(int x,int y){
	if(b[y-1]-b[x-1]-(y-x)*(MAXX-a[y])<=m){
		return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=MAXX-a[i];
		b[i]+=b[i-1];
	}
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(pd(mid,i)){//ok
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		if(pd(l,i)){
			ans=max(ans,i-l+1);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5
2 1 2 4 8 9
*/
