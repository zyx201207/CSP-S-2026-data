//GZ-S00087 道真仡佬族自治县民族中学 韩诚博 
#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[500005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
    	cin>>n>>d;
    	for(int j=0;j<n;j++){
    		cin>>a[j];
		}
		sort(a,a+n);
		int ans=0;
		for(int j=1;j<n;j++){
			for(int k=0;k<n;k++){
				if(a[k]<0){
					int z=0,x=a[k]+(0-a[j]);
				    if((x-z>d)&&((x-z)%2==1)){
					    ans++;
				    }
				}
				else if((a[j]-a[k]>d)&&((a[j]-a[k])%2==1)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
}

