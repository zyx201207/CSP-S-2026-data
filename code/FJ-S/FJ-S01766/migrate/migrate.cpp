#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long ans,l,r;
	int c,t,n,d,a[2000005],pp;
	cin>>c>>t;
	for(int jojo=1;jojo<=t;jojo+=1){
		cin>>n>>d;
		l=1;
		r=0;
	    for(int i=1;i<=n;i++){
	    	cin>>a[i];
		}
		for(int i=2;i<=min(3,n);i++){
			if(a[i]-a[i-1]<=d){
				l+=1;
			}
			else{
				l=1;
			}
		}
		pp=0;
		ans=0;
		for(int i=4;i<=n;i++){
			if(a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d){
				if(pp==0){
					pp=1;
				}
				else{
					ans+=(l-1)*(r+1);
			    	l=r+2;
		    		r=0;
				}
			}
			else{
				if(a[i]-a[i-1]<=d){
					if(pp==0){
						l+=1;
					}
					else{
						r+=1;
					}
				}
				else{
					if(pp==1){
						ans+=(l-2)*(r+1);
					    l=0;
					    r=0;
					    pp=0;
					}
				}
			}
			if(i==n){
				if(pp==1){
					ans+=(l-2)*(r+1);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
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
*/
