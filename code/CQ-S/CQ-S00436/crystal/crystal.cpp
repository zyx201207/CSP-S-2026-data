#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int check(int x){
	int t;
	for(int i=1;i<=n;i++){
		if(a[i]>x){
			t=i-1;
			break;
		}
	}
	int num=0;
	for(int i=1;i<=t;i++){
		num+=(x-a[i]);
	}
	return num;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int sum=0;
	for(int i=1;i<n;i++){
		sum+=a[n]-a[i];
	}
	if(sum<=m){
		cout<<n;
	}else{
		int l=a[1],r=a[n],res=a[1];
		int max_num=0;
		while(l<=r){
			int mid=l+(r-l)/2;
			int num=check(mid);
			if(num<=m){
				max_num=max(num,max_num);
				l=mid+1;
				res=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<res<<endl;
		int ans1;
		for(int i=1;i<=n;i++){
			if(a[i]>res){
				ans1=i-1;
				break;
			}
		}
		int num=0,k=LLONG_MAX;
		for(int i=1;i<=n;i++){
			if(a[i]>k){
				break;
			}
			if(a[i]>res){
				k=a[i];
			}
			if(a[i]==k) num++;
		}
		cout<<ans1<<' '<<num+m-max_num;
	}
	return 0;
}
