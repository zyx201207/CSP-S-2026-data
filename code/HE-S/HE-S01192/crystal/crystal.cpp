#include<bits/stdc++.h>
using namespace std;
int n;
int m;
const int MAXN=5e5+5;
int a[MAXN];
int b[MAXN];
int s[MAXN];
bool check(int l,int r){
	return (b[r]-(l-r)*a[r]+s[l-1]<=m);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=max(a[i+1]-a[i],b[i-1]);
	}
	for(int i=1;i<n;i++){
		s[i]=s[i-1]+b[i];
	}
	int ans=0;
	for(int i=1;i<n;i++){
		int l=i+1,r=n-1,pos=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				pos=mid;
				l=mid+1;
			}
			else r=mid-1; 
		}
		ans=max(ans,pos-i+2);
	}

	cout<<ans<<endl;
	return 0;
} 
