#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long m,n,a,b,c,d,k[N],p[N],be[N],dui[N],sum,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
	}
	sort(k+1,k+1+n);
	for(int i=1;i<n;i++){
		p[i]=k[i+1]-k[i];
	}
	for(int i=1;i<n;i++){
		be[i]+=be[i-1]+p[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<k[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<n;i++){
//		cout<<p[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<n;i++){
//		cout<<be[i]<<" ";
//	}
	long long l=1,r=1;
//	sum=k[1];
	while(l<=r&&r<=n&&l<=n){
		while(sum<=m&&r<=n&&l<=n){
			r++;
			sum+=p[r-1]*(r-l);
//			cout<<sum<<"@"<<" "<<r<<endl;
			ans=max(ans,r-l);
		}
		while(sum>m&&r<=n&&l<=n){
			l++;
			sum=sum-(be[r-1]-be[l-2]);
//			cout<<"$"<<" "<<l<<" ";	
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}