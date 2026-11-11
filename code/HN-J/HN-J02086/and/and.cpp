#include<bits/stdc++.h>
using namespace std;
//Trick||Treat!
long long a[100005],n,m,ans;
long long b[105];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(long long j=0,y=1;j<=30;j++,y*=2){
			b[j]+=bool(a[i]&y);
		}
	}
	for(int k=30;k>=0;k--){
		if(b[k]>=m){
			long long x=1<<k;
			for(int i=1;i<=n;i++){
				if(a[i]&x){
					continue;
				}
				for(long long j=0,y=1;j<=30;j++,y*=2){
					b[j]-=bool(a[i]&y);
				}
				a[i]=0xffffffff;
			}
		}
	}
	for(int i=30;i>=0;i--){
		ans*=2,ans+=(b[i]>=m);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
