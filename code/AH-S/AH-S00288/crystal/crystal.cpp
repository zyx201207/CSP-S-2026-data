#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],l1,l2,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			l1=0;
		}
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			l2=0;
		}
	}
	if(l1==1){
		long long l=1;
		while(m>0&&ans<n){
			m-=l;
			ans++;
			l++;
		}
		cout<<ans;
		return 0;
	}
	if(l2==1){
		sort(a+1,a+n+1);
		long long l=a[2]-a[1],r=a[2]-a[1];
		while(m>0&&ans<n){
			m-=l;
			ans++;
			l+=r;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		long long l=m,j=i+1,cnt=1;
		while(l>=cnt*b[j]&&j<=n){
			l-=cnt*b[j];
			cnt++;
			j++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
