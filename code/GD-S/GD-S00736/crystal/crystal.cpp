#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int a[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int sum=m;
	int ans=0;
	int q=1,j=n;
	while(q){
		j--;
		sum-=(a[n]-a[j]);
		if(sum>=0){
			ans++;
		}else{
			q=0;
		}
	}
	if(ans>0){
		ans++;
	}
	cout<<ans;
	return 0;
}
