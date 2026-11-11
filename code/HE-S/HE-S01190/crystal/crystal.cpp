#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n = 0;
	long long m = 0;
	cin>>n>>m;
	for(long long i = 0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1,cmp);
	

	int ans = 0;
	for(int i = 0;i<n;i++){
		int cnt = 1;
		int m1 = m;
		for(int j = i+1;j<n;j++){
			if(a[i]-a[j]<=m1){
				m1-=(a[i]-a[j]);
				cnt++;
			}else {
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
