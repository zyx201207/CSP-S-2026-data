#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		long long cnt=0;
		cin>>n>>d;
		vector<int>a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		int p=n/2;
		int i=0,j=n-1;
		while(i<=p&&j>=p){
			if(a[i]>0){
				if(a[j]>0){
					cnt=cnt+a[i]+a[j];
				}
				else cnt=cnt+a[i]-a[j];
			}
			if(a[i]<0){
				if(a[j]>0){
					cnt=cnt-a[i]+a[j];
				}
				else cnt=cnt-a[i]-a[j];
			}
			i++;
			j--;
		}
		if(n%2) cnt=cnt/(n-1);
		else cnt=cnt/n;
		cout<<cnt/2<<endl;
	}
	return 0;
}
