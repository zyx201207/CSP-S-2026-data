#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N];
bool check(int x){
	long long sum=0;
	int cnt=1;
	for(int i=x-1;i>=1;i--){
		//cout<<a[i]<<" ";
		sum+=a[x]-a[i];
		if(sum>m){//cout<<endl;
			ans=max(ans,cnt);
			return false;
		}
		cnt++;
	}//cout<<endl;
	ans=max(ans,cnt);
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		check(i);
	}
	cout<<ans;
	
	return 0;
}
