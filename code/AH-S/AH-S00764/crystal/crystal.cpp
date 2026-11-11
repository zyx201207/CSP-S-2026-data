#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,ans=0;
int a[N],c[N],sum[N];
bool check(){
	int last=a[2]-a[1];
	for (int i=3;i<=n;i++){
		if (a[i]-a[i-1]!=last){
		   return false;
        }
    }
	return true;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if (check()){
		int c=a[2]-a[1];
		int cnt=1,p=c;
		while (m>0){
            m-=p;
            if (m<=0) break;
            p+=c;
            cnt++;
        }
        cout<<cnt<<'\n';
        return 0;
    }
	for (int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for (int i=2;i<=n;i++){
		for (int j=1;j<=i;j++){
			int s=(sum[i]-sum[j-1]+m)/(i-j+1);
			if (s>=a[i]){
			    ans=max(ans,i-j+1);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}	
