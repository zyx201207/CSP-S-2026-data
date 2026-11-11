#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=1;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long hm=m;
			int hnum=1;
			for(int j=i-1;j>=1;j--){
				long long k=a[i]-a[j];
				if(k<=hm){
					hm-=k;
					hnum++;
				}
				else
					break;
			}
			ans=max(ans,hnum);
		}
		cout<<ans;
		return 0;
	}
	else{
		int l=1;
		long long dis=0;
		for(int i=2;i<=n;i++){
			long long p=1LL*(i-l)*(a[i]-a[i-1]);
			dis+=p;
			while(dis>m && l<i){
				dis=dis-(a[i]-a[l]);
				l++;
			}
			ans=max(ans,i-l+1);
		}
		cout<<ans;
	}
	return 0;
}
