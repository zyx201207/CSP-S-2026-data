#include<bits/stdc++.h>

using namespace std;
long long n,m,a[500005],b[500005],c[500005],x,t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(b,0,sizeof(b));
	for(long long i=0;i<n;i++)cin>>a[i];
	while(x<n){
		for(long long i=0;i<n;){
			for(long long j=0;j<t;j++){
				if(b[j]==a[i]){
					long long r=0;
					for(long long k=t-1;k>=j;k--){
						b[k]=0;
						r++;
					}
					t=t-r-1;
				}
			}
			b[t]=a[i];
			i++;t++;
			if(i==n-1){
				x++;
				for(long long l=0;l<t;l++){
					c[b[l]]++;
				}
			}
		}
	}
	for(long long i=1;i<=m;i++)cout<<c[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
