//GZ-S00090,欧阳李樾,贵阳市第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,b[N],a[N],c[N],cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(b+1,b+n+1);
	for(int i=1;i<n;i++) a[i]=c[i]=b[i+1]-b[i];
	for(int i=1;i<n;i++) c[i]+=c[i-1];
	for(int i=1,j=1,k=1;j<n;j++,k++){
		cnt+=k*a[j];
		if(cnt>m){
			cnt-=c[j]-c[i-1];
			k--;
			i++;
		}else ans=max(ans,j-i+1);
	}
	cout<<ans+1;
	return 0;
}
