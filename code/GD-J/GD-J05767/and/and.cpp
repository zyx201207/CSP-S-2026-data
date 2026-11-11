#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005],sum,cnt;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		sum=1000000009;
		for(int j=i;j<m+i;j++){
			if(sum>a[j]){
				sum=a[j];
			}
		}
		cnt=max(sum,cnt);
	}
	cout<<cnt;
	return 0;
}
