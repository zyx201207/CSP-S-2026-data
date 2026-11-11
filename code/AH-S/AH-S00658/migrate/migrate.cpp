#include<bits/stdc++.h>
using namespace std;

int c,t,n,d,a[2000100],dpp[2000100];
long long cnt;


int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin>>c>>t;
    for(int i=0;i<t;i++){
        for(int j=0;j<n;j++){
            dpp[j]=0;
        }
        cin>>n>>d;
        for(int j=0;j<n;j++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int j=0;j<n;j++){
            for(int k=j+1;k<n&&a[k]<a[j]+d;j++){
                if(dpp[k]==0){
                    dpp[k]=dpp[j]+1;
                }
                else{
                    dpp[k]=min(dpp[k],dpp[j]+1);
                }
            }
        }
        vector<int> tong(n);
        for(int j=0;j<n;j++){
            tong[dpp[j]]++;
        }
        cnt=0;
        for(int j=1;j<tong.size();j++){
            cout<<tong[j];
            if(tong[j]>=2){
                cnt+=tong[j]*(tong[j]-1)/2;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}