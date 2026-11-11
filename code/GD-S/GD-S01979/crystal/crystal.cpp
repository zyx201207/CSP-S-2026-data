#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long N=5e5+5;
long long n,m;
long long a[N],b[N],need[N],c[N],cost;
int ans,maxc,cnt=1; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			cnt++;
			//cout<<cnt<<" ";
		}
		else{
			maxc=max(maxc,cnt);
			cnt=1;
		}
	}
	maxc=max(maxc,cnt);
	//cout<<endl;
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		//cout<<b[i]<<" ";
	}
	//cout<<endl;
	for(int i=1;i<=n;i++){		
	    c[i]=(i-1)*b[i-1];
		need[i]=need[i-1]+c[i];
		//cout<<need[i]<<" ";
	}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		//cout<<c[i]<<" ";
	}
	//cout<<endl;
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&need[i]-need[j]-(j-1)*b[i-1]>m){
		//cout<<i<<" "<<j<<" "<<need[i]-need[j]<<" "<<(j-1)*b[i-1]<<endl;			
			j++;
		}	
		ans=max(ans,i-j+1);
	}
	cout<<max(maxc,ans);
	//cout<<maxc<<" "<<ans;
	return 0;
}
/*
3 1
1 100 101

315275
313324
*/
