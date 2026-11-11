#include<bits/stdc++.h>
using namespace std;
long long m,n;
int a[200005];
int b[200005][200];
int c[200005],maxn,ans1,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		int k=0;
		while(a[i]){
			b[i][100-k]=a[i]%2;
			a[i]/=2;
			k++;
		}	
		c[i]=k;
		maxn=max(maxn,k);
	}
	for(int i=maxn;i>=0;i--){
		ans1=0;
		for(int j=0;j<n;j++){
			if(b[j][100-i]==1)ans1++;
			if(ans1==m){
				c[i]=1;
				break;
			}
		}
	}
	for(int i=100;i>=0;i--){
		ans+=c[i]*(2^(i+1)); 
	}
	cout<<ans;
	return 0;
}

