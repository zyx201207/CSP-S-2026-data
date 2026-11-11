#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
long long n,m;
long long a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a,a+n+1);   
	for(int i=n;i>0;i--){
		long long sum=0;
//		int ans=0;
		for(long long j=1;j<i;j++){
			long long x=a[i]-a[j];
			sum+=x;
//			ans++;
//			cout<<sum<<" ";
			if(sum>m){
				break;
			}
		}
//		cout<<endl;
		if(sum<=m){
			cout<<i;
			return 0;
		}
	}
	cout<<"1";
	return 0;
}
