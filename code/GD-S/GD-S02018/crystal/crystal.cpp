#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0;
long long a[100001];
int q[100001];
long long b[100001];
long long p[100001];
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int kg=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			kg=1;
		}
	}
	if(kg==0){
		cout<<m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i and a[i]>=a[j]){
				q[++cnt]=a[i]-a[j];
				b[cnt]=i;
				p[cnt]=j;
			}
			if(j!=i and a[j]<a[j]){
				q[++cnt]=a[j]-a[i];
				b[cnt]=i;
				p[cnt]=j;
			}
		}
	}
	int kg5=0;
	for(int i=2;i<=n;i++){
		if(q[i-1]!=q[i]){
			kg5=1;
		}
	}
	if(kg5==0){
		cout<<1<<endl;
		cout<<m/q[1];
		return 0;
	}
	while(m!=0){
		int ll=INT_MAX;
		for(int i=1;i<=cnt;i++){
			ll=min(ll,q[i]);
		}
		if(m>=ll and ll!=0){
			m-=ll;
			for(int i=1;i<=cnt;i++){
				if(ll==q[i]){
					for(int j=1;j<=n;j++){
						for(int k=1;k<=n;k++){
							if(b[i]==j and p[i]==k){
								if(a[j]>=a[k]){
									q[i]=a[j]-a[k];
								}
								if(a[j]<a[k]){
									q[i]=a[k]-a[j];
								}
							}
						}
					}
				}
			}
			ans++;
		}
		else{
			break;
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i and a[i]>=a[j]){
					q[++cnt]=a[i]-a[j];
					b[cnt]=i;
					p[cnt]=j;
				}
				if(j!=i and a[j]<a[j]){
					q[++cnt]=a[j]-a[i];
					b[cnt]=i;
					p[cnt]=j;
				}
			}
		}
	}
	cout<<ans;
}
