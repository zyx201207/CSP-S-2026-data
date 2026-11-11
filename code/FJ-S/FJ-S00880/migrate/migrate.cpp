#include<bits/stdc++.h>
using namespace std;
int c,t,n,j,sum,k;
long long d,qian;
long long a[2000001],b[2000001];
int main(){
		freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
    	cin>>n>>d;
    	memset(a,0,sizeof(int)*(n));
    	memset(b,0,sizeof(int)*(n));
    	j=1,sum=0;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
    		if(a[j]+d<a[i]){
    			b[j]=i-j-1;j++;
    			while(a[j]+d<a[i]){
    				b[j]=i-j-1;
    				j++;
				}
			}
			if(i==n){
				while(j!=n){
					b[j]=i-j;
					j++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			qian=1;
			if(b[i]+i-1>0&&b[i]+i-1<=n){
				if(b[i]==2&&b[b[i]+i-1]==2){
				k=i-1;
				while(k>0){
					if(b[k]==1)qian++;
				}
				sum+=qian;
			}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
