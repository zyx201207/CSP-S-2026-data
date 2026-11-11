#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+9,inf=1e8+9;
long long a[N],s[N],q[N],f[N];

void solved(){
	long long n,m,cnt=1,ans=-inf,find=0; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long k=n+1;
	long long mid=k/2;
	for(int i=1;i<=n;i++){
		s[i]=abs(a[mid]-a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		cnt =1;
		for(int j=i;j<n;j++){
			f[i]+=s[j];
			if(m<f[i]){
				cnt=1;
				break;
			} else{	
				ans=max(cnt,ans);
				cnt++;
			}
		}		
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solved();
	return 0;
}  
