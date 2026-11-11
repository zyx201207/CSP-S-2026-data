#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,cont;
    long long a[1000000];
    int ans;
    long long ct;


    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
    cin>>a[i];
    }
    for(long long i=0;i<n;i++){
			if(a[i]>a[i+1])swap(a[i],a[i+1]);
    }
	cont=a[n/2];
    for(long long i=0;i<n;i++){
    a[i]-=cont;
    if(a[i]==0)ans+=1;
    ct=max(a[i],a[i+1]);

    };

    while(m>0){
		for(long long i=0;i<n;i++){
			if(a[i]<0){
				a[i]=0-a[i];
			};
			if(ct==0)continue;
			else {
				m-=a[i];
				ans+=1;

			};if(m<=0)break;
		};
	};
	cout<<ans<<endl;
    return 0;
}
