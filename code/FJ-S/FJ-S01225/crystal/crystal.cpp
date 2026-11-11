#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans,maxans=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++){
		ans=1;
		int M=m;
		for(int j=i+1;j<=n;j++){
			if(a[i]-a[j]>m){
				break;
			}
			else{
				ans++;
				M-=a[i]-a[j];
			}
		}
		maxans=max(maxans,ans);
	}
	cout<<maxans;
	return 0;
}
