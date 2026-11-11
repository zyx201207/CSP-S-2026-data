#include<bits/stdc++.h>
#define int long long
//kkksc03 ten thousand age!
//it is easy,but I find no way. SOS
using namespace std;
int n,m,ans,a[500005],b[500005],c[500005],d[500005],e[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;
	}
	ans=1;
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	for(int i=n;i>=2;i--){
		if(c[i])d[i]=c[i];
		else d[i]=d[i+1];
	}e[0]=1;
	for(int i=1;i<=n;i++){
		e[i]=e[i-1]+c[i];
	}
	int i,j=1;
	for(i=2;i<=n;i++){
		if(m-c[i]*b[i-1]>=0){
			m-=c[i]*b[i-1];
			b[i]+=b[i-1];
			ans=max(ans,b[i]);
		}else {	
		/*
			while(m-c[i]*b[i-1]<0){
				if(b[j]){
					m+=(e[i]-e[j]);
					b[j]--;
					b[i-1]--;
				}else j++;
			}
			
		*/
			int j=i-b[i-1]+1,l=j;
			while(m-c[i]*b[i-1]<0&&j<=i){
				m+=(e[j+1]-e[l])*b[j];
				b[i-1]--;
				j++;
			}b[i-1]--;
			m-=c[i]*b[i-1];
			b[i]+=b[i-1];
			ans=max(ans,b[i]);
			b[i-1]--;
		}	
		if(ans>n/2&&ans>b[i])break;
		//cout<<a[i]<<" "<<c[i]<<" "<<ans<<" "<<m<<" ";
	}
	cout<<ans;
	return 0;
}
/*
114514
`~`
$_$
SOS
ff is the most beautiful.
*/
