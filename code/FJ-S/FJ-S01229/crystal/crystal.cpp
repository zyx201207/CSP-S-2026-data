#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
bool cmp(int x,int y){
	return x<y;
}
ll n;
ll m;
int a[maxn];
ll b[maxn];
int main(){
	freopen(crystal.in,"r",stdin);
	freopen(crystal.out,"w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(a[l]<a[mid]){
			l=mid+1;
		}
		if(a[r]>a[mid]){
			r=mid-1;
		}
	}	
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(int i=1;i<=n;i++){
		if(r*a[r]-b[r]>m){
			r--;
		}
		if(r*a[r]-b[r]<=m){
			r++;
			if(r*a[r]-b[r]>m){
				cout<<r-1<<endl;
				break;
			}
		}
	}
	return 0;
} 
