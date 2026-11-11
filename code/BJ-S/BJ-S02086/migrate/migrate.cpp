#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int l,r,cnt;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d;
    cin>>c>>t;
    while(t--){
        cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
                cin>>a[i];
        }
        if(n==2) cout<<"0"<<endl;
        else{
            int r=l+1;
                if(abs(r-l)<=d&&l==1){
                    l+=1;
                    r=l+1;
                }
                if(abs(r-l)<=d&&l!=1&&abs(l-d)<0&&r!=n){
                    l+=1;
                    r=l+1;
                    cnt++;
                }
                if(abs(r-l)<=d&&l!=1&&abs(l-d)<0&&r!=n){
                    cout<<"0"<<endl;
                }
            if(abs(r-l)<=d&&l!=1||abs(l-d)>=0) cnt++;
            }
            cout<<cnt;
        }

    return 0;
    }

