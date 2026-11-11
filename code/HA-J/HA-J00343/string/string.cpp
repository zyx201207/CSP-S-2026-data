#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mid,ans;
int f=0;
const int N=2e5;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mid+=a[i];
	}
	if(mid%2!=0)f=1;
	mid=mid/2+f;
	int l=1;
	int r=n;
	while(l<r){
		int x=min(a[l],a[r]);
		if(c[l]!=c[r])
			ans+=x;
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else if(a[l]<a[r]){
			a[r]-=a[l];
			l++;
		}
		else {
			l++;
			r--;
		}
		
	}
	cout<< ans;
	return 0;
} 
