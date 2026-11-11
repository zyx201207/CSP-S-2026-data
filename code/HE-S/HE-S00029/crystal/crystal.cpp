#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],ans,_m;
int _ans_2(int x){
	int ret=0;
	for(int i=0;i<n;i++){
		if(a[i]==a[x]){
			ret++;
		}
	}
	return ret;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(i==0){
			ans=1;
		}
		_m=m;
		for(int j=i-1;j>=0&&_m!=0;j--){
			while(_m!=0&&a[j]!=a[i]){
				a[j]++;
				_m--;
			}
		}
		ans=max(_ans_2(i),ans);
	}
	cout<<ans;
	return 0;
} 
