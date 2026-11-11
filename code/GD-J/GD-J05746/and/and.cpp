#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k=1,a[200010],f;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//Trick||Treat!
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	int t=a[m];
	while(t>1)
	t=t/2,k=k*2,f++;
	int ans=k;
	for(int i=1;i<=n;i++){
		if(a[i]<k){
			n=i-1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]>=2*k)a[i]%=2*k;
	}
	for(int i=1;i<=f;i++){
		int s=0;
		for(int j=1;j<=n;j++){
			if(a[j]%k>=k/2)s++;
		} 
		k=k/2;
		if(s>=m){
			ans+=k;	
			for(int j=1;j<=n;j++){
				if(a[j]%(k*2)<k)a[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
