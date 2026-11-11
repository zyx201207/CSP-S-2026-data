#include<bits/stdc++.h>
using namespace std;
long long n,m,x,maxx=-1;
long long a[200005][35]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(m==1){
			cout<<x;
			return 0;
		}
		long long j=0;
		while(x!=0){
			a[i][j]=x%2;
			x/=2;
			j++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			long long cnt=0;
			for(int l=0;l<=30;l++){
				if(a[i][l]==a[j][l] && a[i][l]==1){
					cnt+=pow(2,l);
				}
			}
			maxx=max(maxx,cnt);
		}
	}
	cout<<maxx;
	return 0;
}
