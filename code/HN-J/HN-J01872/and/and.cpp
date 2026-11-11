#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
long long a[N];
int n,m;
long long ans=0,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==n){
		ans=(1<<n)-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=(1<<m)-1;i++){
		int ii=i;
		s=(1<<m)-1;
		int j=1;
		while(ii>0){
			if(ii%10==1){
				s=s&a[j];
			}
			j++;
			ii/=10;
		}
		ans=max(s,ans);
	}
	cout<<ans;
	}
	return 0;
} 
