#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5;
const int INF=0x3f3f3f3f;
int n;
ll m;
int ans;
ll a[N];
ll q[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	q[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);

		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
		}
	ans=-INF;
	int j=0;
	for(int i=1;i<=n;i++){
		//cout<<i<<" "<<j<<" "<<a[i]<<" "<<q[i]<<" "<<q[j]<<" "<<m<<endl;
		if((i-j)*a[i]<=(q[i]-q[j]+m)){
			ans=max(ans,i-j);
			//cout<<j<<" "<<i<<endl;
		}
		else{
			while(1){
				if(j>=i)break;
				if((i-j)*a[i]<=(q[i]-q[j]+m)){
					break;
				}
				j++;
			}
			ans=max(ans,i-j);
		}
	}
	cout<<ans<<endl;
	return 0;
}
