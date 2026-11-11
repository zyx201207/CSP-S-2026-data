#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	int mmax=-9999;
	for(int i=1;i<=n;i++){
		int cnt=1,mm=m;
		for(int j=i-1;j>=1;j--){
			if(mm-(a[i]-a[j])>=0){
				cnt++;
				mm-=(a[i]-a[j]);
			}else{
				break;
			}
		}
		mmax=max(mmax,cnt);
	}
	
	cout<<mmax;
	
	return 0;
}
