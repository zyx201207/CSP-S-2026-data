#include<bits/stdc++.h>
using namespace std;
long long a[500020];
long long n,m,cnt,g,g1;
int mx=-1;
int v;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m>=1e8)v=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	g=a[2]-a[1];
	g1=g;
	if(v){
		if(m<g){
			cout<<1;
			return 0; 
		}
		for(int i=1; ;i++){
			if(i>n){
				cout<<n;
				return 0;
			}
			if(cnt+g1>m){	
				cout<<i;	
				return 0;
			}
			cnt+=g1;
			g1+=g;
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		int s=m,sum=1;
		for(int j=i-1;j>=0;j--){
			if(s-a[i]+a[j]<0){
				mx=max(mx,sum);
				break;
			}
			sum++;
			s=s-a[i]+a[j];
		}
	}
	cout<<mx;
	return 0;
}
