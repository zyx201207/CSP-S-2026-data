#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate3.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d,cnt=0;
		cin>>n>>d;
		vector<long long> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			if(i<=d) continue;
			if((a[i]-a[i-1])>d) continue;
			for(int j=1;j<i;j++)
			{
				if((a[i]-a[j])<=d) continue;
				if((a[i]-a[j])%d==1){
					if((a[i]-a[j])/d!=((a[i]-a[j])/(d-1)-1)) cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
