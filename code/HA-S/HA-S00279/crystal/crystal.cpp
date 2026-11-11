//1
#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long t=m;
		int j=i-1,sum=1;
		while(1){
			if(j==0){
				break;
			}
			if(t>=a[i]-a[j]){
				t=t-(a[i]-a[j]);
				j--;
				sum++;
			}else{
				break;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
