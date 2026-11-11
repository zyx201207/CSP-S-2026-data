#include<bits/stdc++.h>
using namespace std;
const int N=2000006,M=5010;
int tt,c;
long long n,d;
long long a[N],bs[N],rs[N],tot[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>c>>tt;
    if(c==11 || c==12){
    	while(tt--){
    		cin>>n>>d;
    		for(int i=1;i<=n;i++)  cin>>a[i];
    		if(n<=2){
    			cout<<0<<'\n';
    			continue;
			}  
    		long long l=a[2]-a[1];
    		long long r=d/l;
    		if(r<=1){
    			cout<<0<<'\n';
    			continue;
			}
			l=2ll*r-1;
			long long ans=max(0*1ll,n-l);
			cout<<ans<<'\n';
		}
		return 0;
	}
    while(tt--){
    	cin>>n>>d;
    	for(int i=1;i<=n;i++) cin>>a[i];
    	long long ans=0;
    	for(int i=1;i<n;i++){
    		for(int j=0;j<=n;j++){
    			rs[j]=0,bs[j]=0,tot[j]=0;
			}
    		bs[0]=1;
    		int l=i;
    		for(int j=i+1;j<=n;j++){
    			while(a[j]-a[l]>d){
    				bs[rs[l]]-=tot[l];
					l++;
				} 
    			if(l==j){
    				break;
				}
				int mr=rs[l];
				if(bs[mr]==2){
				//	cout<<i<<" "<<j<<endl;
					ans++;
				}
				rs[j]=mr+1;
				tot[j]=bs[mr];
				bs[rs[j]]+=tot[j];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 

/*
-O2 -std=c++14 -static
-static-libgcc

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

11 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
6 5
1 3 6 7 8 10

0 1
6 5
1 3 6 8 9 10

0 1
8 3
1 2 3 4 5 6 7 8
*/
