#include<bits/stdc++.h>
using namespace std;
long long n,q;
long long a,ans;
string z;
char w;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a>>w;
        for(long long y=1;y<=a;y++){
            z+=w;
        }
    q+=a;
    }
    //for(int s=0;s<q;s++)
        //cout<<z[s];
   // cout<<endl;
    long long v=q-1;
    for(long long i=0;i<q/2;i++){
        if(z[i]!=z[v]){
            ans+=1;//cout<<z[i]<<"1"<<z[v]<<endl;
        }


        v-=1;
    }
    cout<<ans;
return 0;
}
