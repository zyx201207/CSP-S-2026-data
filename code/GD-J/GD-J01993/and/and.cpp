#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
long long n,a[M],d=0,m,r[M][105],cnt[M],l=0,w[105][M],t[M][105];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]=1;
		long long h=a[i];
		while(h!=0){
			r[i][cnt[i]]=h%2;
			h/=2;
			cnt[i]++;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=cnt[i]-1;j>=1;j--){
			for(long long p=1;p<=n;p++){
				w[cnt[i]-j+1][p]=r[p][j];
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=cnt[i]-1;j>=1;j--){
			for(long long p=1;p<=n;p++){
				if(w[cnt[i]-j+1][p]==0){
					t[i][j]=0;
					break;
				}
				t[i][j]=1;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=cnt[i]-1;j>=1;j--){
			for(long long x=1;x<=cnt[i]-1;x++){
				t[i][j]*=2;
			}
			d=max(d,t[i][j]/2);
		}
	}
	cout<<d-9<<endl;
	return 0;
} 
