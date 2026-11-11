#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long c[500005];
long long n;
long long m;
long long ans;
long long y;
int g;
int k;
long long w;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	y=m;
	w=1;
	ans=1;
	g=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			g=0;
		}
		if(i==2){
			k=a[i]-a[i-1];
		}
		if(a[i]-a[i-1]!=k)w=0; 
	}
	if(g!=0){
		for(int i=1;;i++){
			m=m-i;
			if(m>=0 && i<=n){
				ans++;
			}else{
				cout<<ans;
				return 0;
			}
		}
	}
	if(w==1){
		for(int i=1;;i++){
			m=m-k*i;
			if(m>0 && i<=n){
				ans++;
			}else{
				cout<<ans;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		//cout<<a[i]<<endl;
	}
	b[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(a[j-1]==a[i]){
				ans=b[i-1]+1;
				break;
			}
			if(m>=a[i]-a[j]){
				m=m-(a[i]-a[j]);
				if(m>=0){
				ans++;}
			}else{
				break;
			}
		}
		b[i]=ans;
		ans=1;
		m=y;
	}
	ans=0;
	for(int i=1;i<=n;i++){
		//cout<<b[i]<<endl;
		ans=max(ans,b[i]);
	}
	cout<<ans-1;
	return 0;
}
