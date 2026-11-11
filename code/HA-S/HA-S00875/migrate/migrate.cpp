#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c,t,n,d,a[2000005],b;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=2&&a[i-1]+a[2]-a[1]==a[i]){
				b++;
			}
		}
		
		if(b+1==n){
			if(a[3]-a[1]<=d){
				cout<<n-3<<endl;b=0;continue;
			}
			else if(a[4]-a[1]<=d){
				cout<<0<<endl;b=0;continue;
			}
		}	
		if(n==3){
			if(d>a[3]-a[1]){
				cout<<1<<endl;b=0;continue;
			}
			else{
				cout<<0<<endl;b=0;continue;
			}
		}
		if(a[n]-a[1]<=d){
			cout<<n-2<<endl;b=0;continue;
		}
		if(n<=2){
			cout<<0<<endl;b=0;continue;
		}
		
		
		cout<<0<<endl;b=0;
	}
	return 0;
}
/*
     A             CCCCC      
    AA            C     C
   A  A          C       
  AAAAAA         C
 A      A         C     C
A        A         CCCCC
*/
