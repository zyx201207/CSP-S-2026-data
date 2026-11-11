#include<bits/stdc++.h>
using namespace std;
int n,a[500005],cnt;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long p=i,k=m;
		while(k>0&&p>=1){
			if(a[i]-a[p]<=k){
				k-=a[i]-a[p];
				p--;
			}
			else{
				break;
			}	
		}
		if(i-p+1>cnt){
			cnt=i-p+1;
		}
	}
	cout<<cnt;
	return 0;
}
