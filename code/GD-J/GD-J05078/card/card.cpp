#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001]{},b[500001]{},cnt[500001]{};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long q=i,w=1;q<=n;q++,w++){
			b[w]=a[q];
			int t=0;
			for(long long j=1;j<w;j++){
				if(t){
					b[j]=-1;
				}else if(b[j]==a[q]){
					t=1,b[j]=-1;
				}
			}
		}
		for(long long j=1;j<=m;j++){
			for(long long q=1;q<=n+1-i;q++){
				if(j==b[q]){
					cnt[j]+=1;
					break;
				}
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
