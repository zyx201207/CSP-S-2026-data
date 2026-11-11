#include<iostream>
#include<cstring>
#define int long long 
using namespace std;
int n,m,a[2000005],prefr[2000005],suffr[2000005],cpre[2000005],csuf[2000005],t,ans,ccid;
int f[2000005],p[2000005];
int gq;
bool flB;
signed main(){
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>ccid>>t;
	while(t--){
		ans = flB = 0;
		cin>>n>>m;
		memset(cpre,0,sizeof(int)*(n+5));
		memset(csuf,0,sizeof(int)*(n+5));
		for(int i =1;i<=n;i++){
			cin>>a[i];
		}
		for(int i =1;i<=n;i++){
			int l = 1,r = i;
			while(l<=r){
				int mid = l+(r-l)/2;
				if(a[i]-a[mid]<=m)r = mid-1;
				else l = mid+1; 
			} 
			prefr[i] = r+1;
			l = i,r = n;
			while(l<=r){
				int mid = l+(r-l)/2;
				if(a[mid]-a[i]<=m)l = mid+1;
				else r = mid-1;
			}
			suffr[i] = l-1;
			if(prefr[i]==1&&suffr[i]==n){
				gq = i;flB = 1;
			}
		}
		if(n>300&&flB){
			for(int i =1;i<gq;i++){
				int sec = suffr[i];
				if(sec==gq)continue;
				ans += n-sec;
			}
			for(int i =gq+1;i<=n;i++){
				int sec = prefr[i];
				if(sec==gq)continue;
				ans += sec-1;
			}
			cout<<ans<<"\n";continue;
		}
		for(int i =1;i<=n;i++){
			cpre[i] = cpre[prefr[i]]+1;
		}
		for(int i =n;i>=1;i--){
			csuf[i] = csuf[suffr[i]]+1;
		}
		for(int i =1;i<=n;i++){
			for(int j =i+3;j<=n;j++){
				p[i] = 0;f[i] = 1;
				for(int k =i+1;k<=j;k++){
					p[k] = 1e10;f[k] = 0;
					for(int l =k;l>=i+1;l--){
						if(a[k]-a[l-1]>m)break;
						if(p[l-1]+1<p[k]){
							p[k] = p[l-1]+1;
							f[k] = 0;
						}
						if(p[l-1]+1==p[k]){
							f[k] += f[l-1];
						}
					}
				}
				if(f[j]==2){
					++ans;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
} 
/*
0 2
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
10 3
0 3 6 7 8 9 10 11 14 17

0 1
10 333333333333333327
-1000000000000000000 -666666666666666673 -333333333333333346 -111111111111111128 111111111111111090 222222222222222199 333333333333333308 444444444444444417 666666666666666635 999999999999999962
*/
