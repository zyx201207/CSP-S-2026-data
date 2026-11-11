#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans=0;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	for(int i=1;i<n;i++){
		long long anns=1;
		long long tmp=m;
		for(int j=i-1;j>=0;j--){
			if(tmp>=a[i]-a[j]){
				tmp-=a[i]-a[j];
				anns++;
			}else{
				break;
			}
		}ans=max(ans,anns);
	}cout<<ans;
	return 0;
}