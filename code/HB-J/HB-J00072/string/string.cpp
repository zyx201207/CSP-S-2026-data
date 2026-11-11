#include <bits/stdc++.h>
using namespace std;

long long sum[200005],x,n,ans;
char a[200005];
bool f1,f2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a[i];
		sum[i]=sum[i-1]+x;
	}
	long long L=sum[n];
	for(long long i=1;i<=L/2;i++){
		long long j=L-i+1;
		int t1,t2;
		f1=0,f2=0;
		for(int k=0;k<=n;k++){
			if(sum[k]<i&&sum[k+1]>=i){
				t1=k+1;
				f1=1;
			}
			if(sum[k]<j&&sum[k+1]>=j){
				t2=k+1;
				f2=1;
			}
			if(f1==1&&f2==1){
				break;
			}
		}
		
		if(a[t1]!=a[t2]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
