//GZ-S00170 张哲睿 贵阳市新世界学校 
#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[600011];
int ans=1;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long maxn=LLONG_MIN,minn=LLONG_MAX;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n,cmp);
	long long same=a[1];
	int l=1;
	for(int r=2;r<=n;r++){
		m-=1ll*(r-l)*(a[r]-same);
		while(m<0){
			m+=a[r]-a[l];
			l++;
		}
		same=a[r];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
} 
