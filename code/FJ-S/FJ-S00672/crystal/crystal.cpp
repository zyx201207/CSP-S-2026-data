#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N];
bool check(int x){
	//»¬¶¯´°¿Ú
	int sum=0;
	for(int i=1;i<=x;i++)sum+=a[x]-a[i];
	int Min=sum;
	for(int i=1+x;i<=n;i++){
		sum-=a[i-1]-a[i-x];
		sum+=(x-1)*(a[i]-a[i-1]);
		Min=min(Min,sum);
	}
	if(Min<=m)return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
	return 0;
}
/*

*/ 
