#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define CS 2000005
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x*f;
}
int c,t,n,d,x[CS],zdl=INT_MAX,jans=0,zuo1,zuo2,you1,you2;
int sub1(int q,int b,int d,int z){
	if(x[z]-x[q]<=d&&b+1<zdl){
		zdl=b+1;
		return 1-jans;
	}
	if(x[z]-x[q]<=d&&b+1==zdl){
		return 1;
	}
	if(x[z]-x[q]<=d&&b+1>zdl){
		return -2;
	}
	for(int i=q+1;x[i]-x[q]<=d;i++){
		if(sub1(i,b+1,d,z)!=-2){
			jans+=sub1(i,b+1,d,z);
		}
//		cout<<jans<<" now i is "<<i<<" now z is "<<z<<" now zdl is "<<zdl<<endl;
	}
	return jans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(t-x[i]<=0&&t-x[i-1]>=0){
				zuo1=i-1;
				zuo2=i-2;
				you1=i;
				you2=i+1;
			}
		}
		if(n<=300){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					jans=0;
					zdl=INT_MAX;
					if(sub1(i,0,d,j)==2){
						ans++;
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}else{
			if(d<x[3]-x[1]){
				cout<<0<<endl;
				continue;
			}
			for(int i=1;i<=n-3;i++){
				if(x[i+3]-x[i]==2*d-1){
					ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
