#include<bits/stdc++.h>
using namespace std;
int n,sum,cnt,ii;
long long m,a[500005],s[500005],dx,xz,dxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			ii++;
		}
		if(i!=1){
			if(i==2){
				dx=a[i]-a[i-1];
			}
			dxx=a[i]-a[i-1];
			if(dxx==dx){
				xz++;
			}
		}
	}
	if(ii==1){
		int x=0;
		for(int i=1;i<=n;i++){
			x+=i-1;
			if(x==m){
				cout<<i;
				return 0;
			}
			else if(m<x){
				cout<<i-1;
			}
		}
		return 0
	}
	if(xz==n-1){
		cout<<m/dx;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int ans=0;
		long long mm=m;
		for(int j=1;j<=i;j++){
			s[j]=a[i]-a[j];
			if(mm<=0){
				break;
			}
			if(s[j]<0){
				break;
			}
			if(s[j]==0){
				ans++;
				continue;
			}
			if(s[j]<=mm){
				mm-=s[i];
				ans++;
			}
		}
		sum=max(sum,ans);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
