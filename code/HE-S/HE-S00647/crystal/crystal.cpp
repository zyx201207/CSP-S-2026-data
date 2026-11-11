#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
const int N=1e8+5;
long long a[5005],b[5005][5005];
long long f[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool ok=true;
	bool ai=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]+1)
			ok=false;
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				ai=false;
			}
		}
	}
	if(ok){
		long long cnt=0;
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			if(m-(a[n]-a[i])>=0){
				cnt++;
				m-=(a[n]-a[i]);
			}
		}
		cout<<cnt;
		return 0;
	}
	if(ai){
		long long cnt=0;
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			if(m-(a[n]-a[i])<=0)
				break;		
			cnt++;
			m-=(a[n]-a[i]);
			
		}
		cout<<cnt;
		return 0;
	}
//	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			for(int k=i;k<=j;k++){
//				b[i][j]+=a[j]-a[k];
//			}
//		}
//	}
//	for(int i=1;i<=n;i++)
//		f[i]=1;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			f[b[i][j]]=j-i+1;
//          
//		}
//	}
//	for(int i=1;i<=m;i++)
//		cout<<f[i]<<" ";
	
	return 0;
}
