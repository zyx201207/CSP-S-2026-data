#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],b[N][35],sum;
bool f[N];
int mj=0;
int main () {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	int A=a[i],j=1;
    	while(A>=1){
    		b[i][j++]=A%2;
    		A/=2;
		}
		mj=max(mj,j-1);
	}
    for(int i=mj;i>=1;i--){
    	int cnt=0;
    	for(int j=1;j<=n;j++){
    		if(f[j])continue;
    		if(b[j][i]==1)cnt++;
    		if(cnt>=m)break;
		}
		if(cnt<m)continue;
		for(int j=1;j<=n;j++){
    		if(b[j][i]==0)f[j]=1;
		}
	}
	bool F=0;
	for(int i=1;i<=n;i++){
		if(f[i]==1)continue;
		if(m==0)break;
		m--;
		if(F==0){
			sum=a[i];
			F=1;
			continue;
		}
		sum=sum&a[i];
	}
	cout<<sum;
    return 0;
}
