#include<bits/stdc++.h>
using namespace std;
long long a[2000010]={0};
long long rr[2000010]={0};
long long f[2000010]={0};
long long ll[2000010]={0};
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    if(c>=11&&c<=12){
        while(t--){
            int n;
            long long d;
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];

            }
            int temp=d/(a[2]-a[1]);
            if(temp==0||temp==1) cout<<0<<'\n';
            else if(n-1-(temp*2-1)+1<0) cout<<0<<'\n'; 
            else cout<<n-1-(temp*2-1)+1<<'\n';

        }
    }else if(c>=100000000){

    }
    else {
         while(t--){
    
        int n;
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) f[i]=0;
        for(int i=1;i<=n;i++){
           
            cin>>a[i];
        }
       
        int pl=1;
        
        for(int i=1;i<=n;i++){
            while(pl<n&&a[pl+1]-a[i]<=d) pl++;
            rr[i]=pl;
        

        }
       pl=1;
       
  
        for(int i=1;i<=n;i++){
            while(pl<n&&a[i]-a[pl]>d) pl++;
            ll[i]=pl;
        
        }
        int l=0,r=0;
        int ans=0;
        for(int i=1;i<=n;i++){
            while(r<n&&rr[r+1]<i&&rr[r+1]-ll[i]+1<=2) r++;
            while(l<n&&rr[l+1]<i&&rr[l+1]-ll[i]+1<2) l++;
           
            if(rr[ll[i]]==i) f[i]+=f[ll[i]];
            f[i]+=r-l;
            ans+=f[i];

        }
        cout<<ans<<'\n';
        

    }

    }
   

    return 0;
}