#include<bits/stdc++.h>
using namespace std;
int n,cnt,cnt1,cnt2;
long long m;
int a[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<a[0];
		return 0;
	}
	sort(a,a+n);
	for(int i=n-1;i>0;i--){
		if(a[i]-a[0]<=m){
			for(int j=0;j<i;j++){
				cnt+=abs(a[j]);
			}
			for(int p=0;p<i;p++){
				cnt2+=a[i]-a[p];
			}
			if(cnt2<=m){
				cout<<i+1;
				return 0;
			}
			cnt=0;
			cnt2=0;
		}
	}
	return 0;
}

