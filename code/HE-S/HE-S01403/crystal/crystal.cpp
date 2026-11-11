#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
int flag=-1;
long long a[1000001],c[1000001],s[1000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long d=a[2]-a[1];
	for(int i=1;i<=n;i++){
		c[i]=a[i+1]-a[i];
		if(a[i]==i||d==c[i]) continue;
		else flag=1;
	}
	if(flag==-1){
		for(int i=d;;i+=d){
			if(m>=0){
				m-=i;
				ans++;
			}
			else if(m<0){
				cout<<ans;
				return 0;
			}
		}
	}
	else if(flag==1){
		long long w=m;
		for(int i=1;i<=n;i++){
			s[i]=1;
		}
		for(int i=1;i<=n;i++){
			m=w;
			for(int j=i-1;j>=1;j--){
				for(int k=j;k<i;k++){
				m-=c[k];
				if(k==i-1&&m>=0){
					s[i]++;
				}
				else if(m<0){
					break;
				}	
				}
			}
		}
		sort(s+1,s+n+1);
		cout<<s[n];
	}
	return 0;
} 
