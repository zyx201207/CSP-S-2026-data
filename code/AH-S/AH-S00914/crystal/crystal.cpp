#include<bits/stdc++.h>
using namespace std;
long long c[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+1+n);
	long long l=1,sum=0,ans=0,Max=0;
	for(int i=1;i<=n;i++){
		sum+=(c[i]-c[i-1])*ans;
		if(sum>m){
			int a=l;
			for(int j=a;j<=i;j++){
				sum-=c[i]-c[j];
				ans--;
				l++;
				if(sum<=m)
					break;
			}
		}
		//cout<<sum<<" "<<l<<" "<<i<<endl;
		ans++;
		Max=max(Max,i-l+1);
		//cout<<Max<<endl;
	}
	cout<<Max;
	return 0;
}
