#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long zd=LONG_LONG_MIN;
		for(int i=1;i<=n;i++){
			zd=max(zd,a[i]);
		}
		cout<<zd;
		return 0;
	}
	if(m==n){
		long long s=a[1];
		for(int i=2;i<=n;i++){
			s=(s&a[i]);
		}
		cout<<s;
		return 0;
	}
	if(m==2){
		long long zd=LONG_LONG_MIN;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				zd=max(zd,(a[i]&a[j]));
			}
		}
		cout<<zd;
		return 0;
	}
	if(m==n-1){
		long long zd=LONG_LONG_MIN;
		for(int i=1;i<=n;i++){
			long long s=1; 
			for(int j=1;j<=n;j++){
				if(j=i) continue;
				s=(s&a[j]);
			}
			zd=max(zd,s);
		}
		cout<<zd;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
