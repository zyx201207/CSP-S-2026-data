#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	if(m==2){
		long long cnt=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)cnt=max(cnt,a[i]&a[j]);
			}
		}cout<<cnt;
		return 0;
	}
	long long cnt=a[n-m];
	for(int i=n-m;i<n;i++){
		cnt=cnt&a[i];
	}cout<<cnt;
	return 0;
}

