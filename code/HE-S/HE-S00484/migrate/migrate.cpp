#include<bits/stdc++.h>
using namespace std;
long long ans,n,d,c,t,x=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int loveccf=1;loveccf<=t;loveccf++){
		cin>>n>>d;
		long long a[20002],b[20002],k=1,p=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(p*d>=a[i]){
			if(k==1){
				k=i;
			}
			else{
				b[i]=p+i-k;
			
			}	
				p++;
				k=i;
			}
			for(int i=4;i<=n;i++){
				if(b[i-1]==b[i]){
					ans++;
					
				}
					
			}
		} 
		cout<<ans<<endl;
		ans=0;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

