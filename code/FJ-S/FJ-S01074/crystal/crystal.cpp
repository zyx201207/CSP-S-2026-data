#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m;
int n;
int sum,ans;
int k;
int x;
ll a[500010],b[500010];
int c[500010];
bool flag,f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		x+=(a[i]==-100);
		flag=(a[i]==i);
	}
	
	sort(a+1,a+1+n);
	sum=a[2]-a[1];
	for(int i=2;i<n;i++){
		if(a[i+1]-a[n]!=sum){
			sum=-1;
			break;
		}
	}
	if(flag||sum!=-1){
		for(int i=n-1;i>=1;i--){
			m-=a[n]-a[i];
			if(m<0) break;
			ans++;
		}
		cout<<ans+1;
		return 0;
	}
	ans=0;
		for(int i=1;i<=n;i++){
			int t=i+1;
			while(a[t]==a[i]&&t<=n){
				t++;
			} 
			b[++k]=a[i];
			c[k]=t-i;
//			if(t==n+1) break;
			i=t-1;
		}
//		cout<<x<<' ';
//		for(int i=1;i<=k;i++){
//			x+=c[i];
//		}
//		cout<<x<<' ';
		for(int i=1;i<=k;i++)
		{
			ll p=m;
			sum=0;
			for(int j=i-1;j>=1;j--){
				if(p<c[j]*(b[i]-b[j])){
					for(int o=c[j];o>=1;o--){
						if(p>=o*(b[i]-b[j])){
							sum+=o;
							p-=o*(b[i]-b[j]);
							break;
						}
					}
					break;
				}
				p-=c[j]*(b[i]-b[j]);
				sum+=c[j]; 
			}
			
			ans=max(ans,sum+c[i]);
//			cout<<sum+c[i]<<' ';
		}
	
	cout<<ans;
	return 0;
}
