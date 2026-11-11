#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,kim;
int a[500005],b[500005];
signed main(){
	//freopen("crystal.in","w",stdin);
	//freopen("crystal.out","r",stdout);
	cin>>n>>m;
	int num=m,ans=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		if(b[i]==b[i+1]){
			kim++;
		}
	}
	ans+=kim;
	if(m==0){
		cout<<kim+1<<endl;
		return 0;
	}
	int mid=(n+1)/2;
	int k=b[mid];
	for(int i=mid-1;i>=1;i--){
		int sum=a[mid]-a[i];
		if(num<sum){
			break;
		}
		num-=sum;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
