//T3 and
#include<bits/stdc++.h>
using namespace std;
int Log(long long x){
	int ans=0;
	while(x){
		ans++;
		x/=2;
	}
	return ans;
}
int n,m;
bool cmp(long long x,long long y){
	return x>y;
}
long long a[200050];
queue<long long>q;
//int f[2050][2050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	sort(a,a+n,cmp);
//	for(i=0;i<n;i++){
//		if(!q.empty()){
//			q.push(a[i]);
//			continue;
//		}
//		if(Log(q.front())==Log(a[i])){
//			q.push(a[i]);
//			continue;
//		}
//		
//	}
//	for(int i=0;i<n;i++)f[i][1]=a[i];
//	for(int i=1;i<n;i++){
//		for(int j=1;j<=m&&j<=i+1;j++){
//			f[i][j]=max(f[i-1][j],f[i-1][j-1]&a[i]);
//			//cout<<f[i][j]<<" ";
//		}
//		//cout<<endl;
//	}
//	cout<<f[n-1][m];
	if(m==1){
		cout<<a[0];
		return 0;
	}
	if(m==2){
		long long ans=0;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				if(i==j)continue;
				long long at=a[i]&a[j];
				ans=max(ans,at);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		long long ans;
		ans=a[0];
		for(int i=0;i<n;i++)ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==3){
		long long ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(i==j||j==k||i==k)continue;
					long long at=a[i]&a[j]&a[k];
					ans=max(ans,at);
				}
			}
		}
		cout<<ans;
		return 0;
	}
}
