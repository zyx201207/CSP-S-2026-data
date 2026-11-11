#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,k,mx,sum,b[N],a[N],p[32];
bool f=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=30;i++){
		p[i]=p[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}else if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	k=floor(log(mx));
	if(mx>p[k]){
		k++;
	}
	for(int i=k;i>=0;i--){
		sum=0;
		for(int j=1;j<=n;j++){
			long long h=a[j]&p[i];
			if(h>0){
				b[++sum]=a[j];
			}
		}
		if(sum>=m){
			f=1;
			break;
		}
	}
	if(f){
		long long ans=b[1];
		for(int i=2;i<=sum;i++){
			ans&=[i];
		}
		cout<<ans;
	}else{
		cout<<"0";
	}
	return 0;
}
