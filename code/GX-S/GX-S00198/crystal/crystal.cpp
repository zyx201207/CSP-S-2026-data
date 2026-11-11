#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,r,l=1,mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int qwe=a[2]-a[1],qq=1;
	for(int i=1;i<=50,i<=n;i++){
		if(a[i]-a[i-1]!=qwe)
		qq=0;
		break;
	}
	if(qq){
        long long res=0,qs;
		for(int i=1;i<=n;i++){
			res+=i;
			qs=i;
			if(res>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<qs;
		return 0;
	}
	sort(a+1,a+n+1);
	r=n;
	while(l<=r){
		mid=(r-l)/2+l;
		long long sum=0;
		for(int i=1;i<mid;i++)sum+=a[mid]-a[i];
		if(sum>m)r=mid-1;
		if(sum==m){
			int qt=0;
			for(int i=mid+1;i<=n;i++){
				if(a[i]==a[mid])qt++;
				else break;
			}
			cout<<mid+qt;
			return 0;
		}
		if(sum<m){
			int qt=0;
			for(int i=mid+1;i<=n;i++){
				if(a[i]==a[mid])qt++;
				else break;
			}
		    l=mid+1;
		    ans=mid+qt;
		}
	}
	cout<<ans;
	return 0;
}
