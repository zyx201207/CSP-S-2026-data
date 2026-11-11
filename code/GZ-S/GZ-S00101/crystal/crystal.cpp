//蒋木铮 贵阳第一中学 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],n,m,mmax=INT_MIN;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int f=1,f1=1;
	for(int i=1;i<=n;i++) if(a[i]!=i) f=0;
	for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f1=0;
	if(f==1||f1==1){
		int s=0;
		sort(a+1,a+n+1);
		for(int j=n;j>=1;j--){
			m-=a[n]-a[j];
			if(m>=0) s++;
			else break;
		}
		cout<<s;
	} 
	else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			int s=0;
			int m1=m,k=a[i];
			for(int j=i;j>=1;j--){
				m1-=k-a[j];
				if(m1>=0) s++;
			}
			mmax=max(mmax,s);
		}
		cout<<mmax;
	}
	return 0;
}
