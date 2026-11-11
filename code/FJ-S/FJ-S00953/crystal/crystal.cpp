#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,ans1;
bool check(int x){
	long long kx=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x) break;
		else{
			kx+=(x-a[i]);
		}
	}
	if(kx<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=a[1],r=a[n];
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=ans) ans1++;
	}
	cout<<ans1;

}	
