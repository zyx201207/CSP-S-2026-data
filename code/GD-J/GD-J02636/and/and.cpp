#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxa=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	int ans=0;
	int wei=log2(maxa);
//	cout<<wei;
	for(int i=wei;i>=0;i--){
		int nans=ans+(1<<i);
		int cnt=0;
		for(int j=0;j<n;j++){
			if((a[j]&nans)==nans){
				cnt++;
//				cout<<a[j]<<' ';
			}
			if(cnt>=m) break;
		}
//		cout<<cnt<<' ';
		if(cnt>=m){
			ans=nans;
		}
//			cout<<nans<<endl;
	}
	cout<<ans;
	return 0;
}

