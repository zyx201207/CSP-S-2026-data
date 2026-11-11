#include<bits/stdc++.h>
using namespace std;
long long check(long long n,long long d){
    if(n%d!=1){
        return 0;
    }else if(n%d==1){
        if(n/d==1){
            return 1;
        }else{return 0;}
    }
}
int main(){
//  cout<<1;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	long long t;
	cin>>c>>t;

	while(t--){
        long long ans=0;
        long long n,d;
        cin>>n>>d;

        for(long long i=1;i<=n;i++){
            long long temp;
            cin>>temp;

        }
        if(n%d==0){
            cout<<0;

            continue;
        }
        for(long long i=d+2;i<=n;i++){
            if(check(i-1,d)){
                ans+=n-i+1;
            }

        }
        cout<<ans;

	}

	return 0;
}
