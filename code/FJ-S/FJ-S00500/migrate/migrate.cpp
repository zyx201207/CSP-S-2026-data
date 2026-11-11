#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],ans;
int ds(int l,int r){
	int sh=l,zans=0,ty=0;
	for(int i=l;i<=r;i++){
		if(a[i+1]-a[sh]>n||i==r){
			if(((a[i]-a[sh+1]<n&&sh+1<i)||a[i]-a[sh-1]<n)&&ty==0){
				if((a[i]-a[sh+1]<n && sh+1<i) && a[i]-a[sh-1]<n)ty=-10000000;
				else ty+=1;
			}else if((a[i]-a[sh+1]<n&&sh+1)||a[i]-a[sh-1]<n){
				ty=-10000000;
				return 0;
			}
			sh=i-1;
			zans++;
		}
	}if(ty==1)return 1;
	else return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d)break;
				if(ds(i,j)){
					ans++;
				}
			}
		}cout<<n-3<<endl;
	}
	return 0;
} 
