#include<bits/stdc++.h>
using namespace std;
long long n,en[500010];
long long m,k;
long long magic=0,ans=0,num=0;
long long chos=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>en[i];
    }
    sort(en+1,en+n+1);


    if(m>1e9){
        num=en[2]-en[1];
        long long y=0;
        for(int i=2;i<=n;i++){
            y+=num*(i-1);
            if(y>m){
                cout<<i-1;
                return 0;
            }
        }
    }



    for(int i=1;i<=n;i++){
        int magic=en[i];
        k=m;
        num=1;int temp=i+1;
        int chos=1;
        while(k>=0 && temp<=n){
            if(magic==en[temp]){
                num++;
                chos++;
            }
            else{
                if(k-(en[temp]-magic)*chos>=0){
                    k-=(en[temp]-magic)*chos;
                    magic=en[temp];
                    num++;
                    chos++;
                }
                else{
                    break;
                }

            }
            temp++;
        }

        if(num>ans){
            ans=num;
        }

    }
    cout<<ans;

    return 0;
}
