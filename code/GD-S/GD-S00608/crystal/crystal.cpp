#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
const int M=1e12+5;
int n,m;
unsigned long long pre[N];
int a[N];
bool check(int i,int mid){
	if(a[i]*(i-mid+1)<=pre[i]-pre[mid-1]+m){
		return 1;
	}
	return 0;
}
bool cmp(int x,int y){
	if(x<0&&y<0) return x>y;
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) a[i]+=M;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int maxn=-1e18;
//	for(int i=1;i<=n;i++) cout << pre[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i,ans=0;//you bu dong
		while(l<=r){
			int mid=(l+r)/2;
			if(check(i,mid)){
				r=mid-1;
			}
			else{
				l=mid+1;
				ans=l;
			}
//			cout << l << " " << r << " " << i-ans+1 << endl;
		}
//		cout << endl;
		maxn=max(maxn,i-ans+1);
	}
	cout << maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

