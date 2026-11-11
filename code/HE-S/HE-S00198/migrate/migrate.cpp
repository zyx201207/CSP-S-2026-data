#include<bits/stdc++.h>
using namespace std;
int t;
int n,d,m;
long long x[2000010];
int g=0;
void kcl(int l,int r,int ans,int f){
	if(ans>f){
		return;
	}
	if(l==r){
		g++;
		return;
	}
	for(int i=l+1;x[i]-x[l]<=d&&i<=r;i++){
		if(g==3){
			return;
		}
		kcl(i,r,ans+1,f);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		int ans=0;
		int cnt=0;
		cin>>n>>d;
		cin>>x[1];
		m=n;
		for(int i=2;i<=n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]>d&&m==n){
				m=i-1;
			}
		}
		for(int y=m;y>1;y--){
			for(int l=1,r=y;r<=m;r++,l++){
				ans=0;
				for(int i=l;i<r;i++){
					int c=i;
					i++;
					while(x[i]-x[c]<=d&&i<=r){
						i++;
					}
					i-=2;
					ans++;
				}
//				cout<<ans<<endl;
				g=0;
				kcl(l,r,0,ans);
				if(g==2){
					cnt++;
				}
			}
			if(cnt>0){
				cout<<cnt<<endl;
				break;
			}
		}
		if(cnt==0){
			cout<<0<<endl;
		}
	}
}
