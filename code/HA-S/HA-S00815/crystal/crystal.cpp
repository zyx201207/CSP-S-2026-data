#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
int sum;
bool f1,f2;
long long ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	f1=true,f2=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i>=1) f1=false;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>=2) f2=false;
		sum+=a[i];
	}
	if(f1) cout<<n;
	else if(f2){
		int det=a[1]-a[0];
		for(int k=1;k<=n;k++){
			m-=k*det;
			if(m>=0) ans++;
		}
		cout<<ans;
	}else{
		sort(a,a+n-1);
		for(int i=n-1;i>=0;i--){
			long long k=m,num=1;
			for(int j=0;j<i;j++){
				int x=a[i]-a[j];
				if(x<=k){				
					k=k-x;
					if(k<0) break;	
					num++;		
				}else break;			
			}
			ans=max(ans,num);
		}
		cout<<ans;
	
	}
	return 0;
}
