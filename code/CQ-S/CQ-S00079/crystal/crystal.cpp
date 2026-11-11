#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = n;i>=1;i--){
		int m1 = m;
		int temp =1;
		for(int j = i-1;j>=1;j--){
			if(m1==0) continue;
			int lo;
			if(a[i]<0 && a[j]<0) lo = abs(a[i]) -abs(a[j]);
			else if (a[i]<0 || a[j]<0) lo = abs(a[i])+abs(a[j]);
			else lo = a[i]-a[j];
			if(m1>=lo) {
				m1-=lo;
				temp++;
			}
		}
		if(temp>ans){
			ans=temp;
		}
	}
	cout<<ans;
	return 0;
}

