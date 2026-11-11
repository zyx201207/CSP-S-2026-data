#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],cnt[N],ans,sum;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1,cmp);
	bool f=0;
	for(int i=30;i>=0;i--){
		sum=0;
		for(int j=1;j<=n;j++){
			if((a[j]>>i)&1==1){
				sum++;
				cnt[sum]=a[j];
			}
			if(sum==m){
				f=1;
				break;
			}
		}
		if(f)break;
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	ans=cnt[1];
	for(int i=2;i<=m;i++){
		ans&=cnt[i];
	}
	cout<<ans;
	return 0;
}

