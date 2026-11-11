#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int b[500005];
int maxx=INT_MIN;
bool cmp(int a,int b){
	return a>b;
}
void check(int mid){
	memset(b,-1,sizeof(b));
	for(int i=1;i<=n;i++){
		if(mid-a[i]>=0)b[i]=mid-a[i];
	}
	int sum=0;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(b[i]!=-1&&sum+b[i]<=m){
			sum+=b[i];
			maxx=max(maxx,i);
		}else{
			return;
		}
	}
	
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=a[1],r=a[n]+m;
	for(int i=l;i<=r;i++){
		check(i);
	}
	cout<<maxx;
	return 0;
} 
