#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int n;
unsigned long long m;
int a[5*maxn],b[5*maxn];
bool solve(int x){
	int sum=0;
	for(int i=1,j=x;j<=n;i++,j++){
		sum=0;
		int o=i;
		while(o<j){
			sum+=(a[j]-a[o]);
			o++;
		}
//		int q=b[j-1]-b[i-1],p=(j-i)*a[j];
//		sum=p-q;
		if(sum<=m) return true;
	}
	return false;
}//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	} 
	sort(a+1,a+n+1);
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(!solve(mid)) r=mid;
		else l=mid;
	}
	cout<<l;
	return 0;
}//Oct31==Dec25?
