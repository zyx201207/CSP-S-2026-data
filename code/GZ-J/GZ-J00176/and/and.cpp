//GZ-J00176遵义红花岗区第四小学娄雨涵 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=-1000;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	if(m==1){
		cout<<ma;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans|a[i];
		}
		cout<<ans;
	}else if(m==2){
		int mm=-1000;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mm=max(a[i]|a[j],mm);
			}
		}
		cout<<mm;
	}else if(m==n-1){
		int mm=-1000;
		int s;
		for(int i=1;i<=n;i++){
			if(i==1){
				s=a[2];
			}else{
				s=a[1];
			}
			for(int j=1;j<=n;j++){
				if(j!=i){
					s=s|a[j];
				}
			}
			mm=max(mm,s);
		}
		cout<<mm;
	}
	return 0;
}
