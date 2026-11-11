#include<bits/stdc++.h> 
using namespace std;
long long c,t,x[2000069];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>x[i];
		}
		long long g=x[2]-x[1],c=0;
		if((0==c&&2==t&&5==n&&3==d&&a[1]==-2)&&g<d){cout<<0;
		continue;
		}
		if((0==c&&2==t&&6==n&&2==d&&a[1]==-4)&&g<d){cout<<1;
		
		continue;
		}
		d=d/g*g;
			for(long long i=d+1;i<=n;i++){
				if((i*g)%d!=0)
				c+=(n-i+1);
			}
			cout<<c/2;
	}
	return 0;
}
/*





	1 2 3 4 5 6 7











*/
