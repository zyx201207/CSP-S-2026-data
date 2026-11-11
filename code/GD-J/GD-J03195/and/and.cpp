#include<bits/stdc++.h>
#include<string>
using namespace std;
const int N=1e7;
long long  b[N],a[N],f=1,p,p1;
long long ans=0;
int n,m;
bool is(long long n1){
	while(n1>1){
		if(n1%2==1) return 0;
		n1/=2;
	}	
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!is(a[i]+1)) f=0;
		ans=max(ans,a[i]);
	}
	if(f){
		int l;
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	else if(m==1){
		cout<<ans;
	}
	else if(m==2){
		ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				else{
					ans=max(ans,a[i]&a[j]);
				}
			}
		}
		cout<<ans;
	}
	else if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=a[i-1]&a[i];
		}
		cout<<a[n];
	}
	return 0;
} 
