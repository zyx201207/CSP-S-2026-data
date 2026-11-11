#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500006];
long long b[5005][5005];
long long c[500006];
long long b2[500006];
int o;
int p;
long long ans=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)continue;
		p=a[2]-a[1];
		if(a[i]-a[i-1]==p) o++; 
	}
	
	if(o==n-1){
		b2[1]=p;
		for(int i=2;i<=n;i++){
			b2[i]=b2[i-1]+p;
		}
		for(int i=1;i<=n;i++){
			c[i]=c[i-1]+b2[i];
		}
		for(int i=1;i<=n;i++){
			if(c[i]>m){
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=a[i]-a[j];
		}
	}
	for(int i=1;i<=n;i++){
		sort(b[i],b[i]+1+i);
	}
	for(int i=1;i<=n;i++){
		long long sum=1;
		long long s=0;
		for(int j=2;j<=i;j++){
			s+=b[i][j];
			sum++;
			if(s>m){
				sum--;
				break;
			} 
				
		}
		if(sum>ans) ans=sum;
	}
	cout<<ans;
	return 0;
}
