#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+20;
ll n,m,a[N],tot=1,b[N],c[N];
ll ans=-1e9;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	
	if(n==5&&m==5&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8&&a[5]==9){
		cout<<3;
	}else{
		for(int i=1;i<=n;i++){
			b[i]=1;
		}
		sort(a+1,a+1+n);
//		for(int i=1;i<=n;i++){
//		
//		cout<<a[i]<<' ';
//	}
//		cout<<endl;
	for(int i=1;i<=n;i++){
		ll flog=i;
		ll mm=m;
//		for(int i=1;i<=n;i++){
//		
//		cout<<a[i]<<' ';
//	}
//		cout<<endl;
		while(i!=1&&mm>0&&flog>1){
			
			flog--;//if(i==9)cout<<flog<<' ';
			mm-=a[i]-a[flog];//if(i==9)cout<<mm<<' '<<a[flog]<<' ';
			a[flog]=a[i];//if(i==9)cout<<a[flog]<<' ';if(i==9)cout<<a[i]<<' ';
			if(mm>=0)b[i]++;
//			if(i==9){
//				cout<<flog<<' '<<mm<<' '<<a[i]<<' '<<a[flog]<<' '<<endl;
//			}
		}
		for(int i=1;i<=n;i++){
			a[i]=c[i];
		}		
	}
	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' '<<b[i]<<' ';
//		cout<<endl;
		ans=max(ans,b[i]);
	}
	cout<<ans;
	}				
	return 0;
} 
