#include <bits/stdc++.h>
using namespace std;
long long s[200010],a[200010][35],b[200010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long g=0,ans=0,n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int f;
		cin>>s[i];
		f=s[i];
		int nn=1;
		while(f!=0){
			a[i][nn]=f%2;
			f/=2;
			nn++;
		}
		b[i]=0;
	}
	for(int j=30;j>=1;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i][j]==1&&b[i]==0){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(a[i][j]!=1){
					b[i]=1;
				}
			}	
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			if(g==0){
				ans=s[i];
				g=1;
			}else{
				ans&=s[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
