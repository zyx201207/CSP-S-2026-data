#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long t[500005];
long long ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		for(long long j=i;j<=n;j++){
			if(t[a[j]]!=0){
				int ind;
				for(long long k=1;k<=j-1;k++){
					//t[a[k]]=0;
					if(a[k]==a[j]) ind=k;
				}
				for(long long k=ind;k<=j-1;k++){
					t[a[k]]=0;
				}
			}
			t[a[j]]=1;
		}
		for(long long j=1;j<=m;j++){
		//	cout<<j<<" "<<t[j]<<endl;
			if(t[j]!=0) ans[j]++;
		//	cout<<ans[j]<<endl;
		}
	}
	for(long long i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
