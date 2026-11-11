#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+n+1);
	int x=a[2]-a[1];
	bool f=true;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=x)
		    f=false;
	}
	if(f==true){
		int tot=0;
		int sum=0;
		int num=0;
		while(sum<=m){
			num+=x;
			sum+=num;
			tot++;
		}
		cout<<tot-1;
	}
	else{
		long long mx=1;
		for(int i=1;i<=n;i++){
			long long sum=0;
			long long num=0;
			long long tot=1;
			for(int j=i-1;j>=1;j--){
				tot++;
				num+=a[i]-a[j];
				sum+=num;
				if(sum>m){
					break;
				}
			}
			mx=max(tot,mx);
		}
		cout<<mx;
	}
	return 0;
}
