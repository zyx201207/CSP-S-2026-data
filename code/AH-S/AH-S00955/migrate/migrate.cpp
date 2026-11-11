#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],f[505][505],m[505][505],ans;    
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
           cin>>n>>d;
            for(int i=1;i<=n;i++)
	        	scanf("%lld",&a[i]);
	        d/=a[2]-a[1];
	        if(n-d*2+1>0&&d>=2) cout<<n-d*2+1<<endl;
	        else cout<<0<<endl;
		}
        fclose(stdin); fclose(stdout);
        return 0;
	}
    while(t--){
        cin>>n>>d; ans=0;
        memset(f,0x3f,sizeof(f));
        memset(m,0,sizeof(m));
        for(int i=1;i<=n;i++)
	    	scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n&&a[i]+d>=a[j];j++){
                f[i][j]=1;
			}
            f[i][i]=0;
		}
	    for(int l=1;l<n;l++)
            for(int i=1;i+l<=n;i++){
			    long long j=i+l; long long k=j-1;
				if(f[i][j]==1) continue;
	        	long long l=i+1,r=j,mid;
	        	while(l!=r){
	         	    mid=(l+r)/2;
		            if(a[mid]+d>=a[j]) r=mid;
		    	    else l=mid+1;
		        }
		        k=l;
				if(f[i][k]<0x3f3f3f3f3f3f3f3f)
			        f[i][j]=f[i][k]+1;
			    if(f[i][k]==f[i][k+2]){
				    if(k+2<=j) m[i][j]=2;
			    }else {
					if(f[i][k]==f[i][k+1]) {
						if(m[i][k]+m[i][k+1]==0) { m[i][j]=1; ans++; }
					}else {
						if(m[i][k]==1) { m[i][j]=1; ans++; }
					}
			    }
            }
        cout<<ans<<endl;
	}
    fclose(stdin); fclose(stdout);
    return 0;
}
