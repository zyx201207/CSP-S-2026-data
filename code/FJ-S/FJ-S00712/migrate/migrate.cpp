#include<bits/stdc++.h>
using namespace std;
int c,T;
long long n,d,a[2000005],dis[2000005],tot[2000005],ans=0;
const long long ze=0;
void test1(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>a[i];
	long long D=a[2]-a[1];
	if(d+1<=D*2)cout<<"0\n";
	else cout<<max(ze,n-(d/D)*2+1)<<"\n";
	return;
}
void test3(){
	cin>>n>>d,ans=0;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<n;++i){
		for(int j=i;j<=n;++j)tot[j]=0;
		int s=i,lasa=i,lasb=i;
		tot[i]=1;
		while(s<n){
			while(s<n&&a[s+1]<=a[lasa]+d)++s;
			if(s==lasa)break;
			if(lasa==lasb||lasa==lasb+1){
				if(tot[lasa]>2)break;
				for(int j=lasa+1;j<=s;++j){
					tot[j]=tot[lasa];
					if(tot[j]==2)++ans;
				}
				lasb=lasa,lasa=s;
			}else{
				if(tot[lasa]>2)break;
				if(tot[lasa]==2){
					for(int j=lasa+1;j<=s&&a[j]<=a[lasa-1]+d;++j)tot[j]=3;
					for(int j=s;j>=lasa+1&&a[j]>a[lasa-1]+d;--j)tot[j]=2,++ans;
					lasb=lasa,lasa=s;
				}else{
					if(tot[lasa-1]>=2){
						for(int j=lasa+1;j<=s&&a[j]<=a[lasa-1]+d;++j)tot[j]=3;
						for(int j=s;j>=lasa+1&&a[j]>a[lasa-1]+d;--j)tot[j]=1;
						lasb=lasa,lasa=s;
					}else{
						if(lasb+2==lasa){
							for(int j=lasa+1;j<=s&&a[j]<=a[lasa-1]+d;++j)tot[j]=2,++ans;
							for(int j=s;j>=lasa+1&&a[j]>a[lasa-1]+d;--j)tot[j]=1;
							lasb=lasa,lasa=s;
						}else{
							for(int j=lasa+1;j<=s&&a[j]<=a[lasa-2]+d;++j)tot[j]=3;
							for(int j=s;j>=lasa+1&&a[j]>a[lasa-2]+d;--j){
								if(a[j]>a[lasa-1]+d)tot[j]=1;
								else tot[j]=2,++ans;
							}
							lasb=lasa,lasa=s;
						}
					}
				}
			}
		}
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	if(c==11||c==12){
		while(T--)test1();
		return 0;
	}
	while(T--)test3();
	return 0;
}
