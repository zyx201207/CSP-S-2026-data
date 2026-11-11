#include<bits/stdc++.h>
using namespace std;
long long n,x[200001],y[200001],sum,ans;
char a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>a[i];
		y[i]=y[i-1]+x[i];
	}
	for(int i=1;i<=n;i++){
		if(y[i]>=y[n]/2){
			int l=i,r=i;
			long long sum,t;
			if(y[i]==y[n]/2) r++,sum=x[r],t=x[l];
			else sum=y[r]-(y[n]/2),t=x[i]-sum;
			while(r<n){
				char p=a[r];
				for(int j=r+1;r<=n;r++){
					if(a[j]==p) sum+=x[j];
					else{
						r=j;
						break;
					}
				}
				for(int j=l-1;j>=1;j--){
					t+=x[j];
					if(t>=sum){
						if(a[j]!=p) ans+=sum-t+x[j];
						l=j,t-=sum;
						break;
					}
					else{
						if(a[j]!=p) ans+=x[j];
					}
				}
				if(a[r]!=a[l]) ans+=t;
				sum=0,t=0;
			}
			cout<<ans;
			return 0;	
		}
	}
	return 0;
}
