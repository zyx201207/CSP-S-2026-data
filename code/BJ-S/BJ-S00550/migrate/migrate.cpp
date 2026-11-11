#include<bits/stdc++.h>
using namespace std;
int t;
long long n[10010];
long long d[10010],A[10010];
long long isl[10010][20010];
int num;
bool model(long long a,long long b,long long c,long long d,long long D){
    return c-a<=D&&d-b<=D;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    cin>>c>>t;
    for(num=0;num<t;num++){
        cin>>n[num]>>d[num];
        long long ans=0;
        for(int i=0;i<n[num];i++){
            cin>>isl[num][i];
        }
        for(int i=0;i<n[num]-3;i++){
            if(model(isl[num][i],isl[num][i+1],isl[num][i+2],isl[num][i+3],d[num])){
                long long cnt=1,cntt=4;
                while(i+cntt<=n[num]&&isl[num][i+cntt]-isl[num][i+cntt-1]<=d[num]){
                    cnt++;
                    cntt++;
                }
                ans+=cnt;
            }
        }
        A[num]=ans;
    }
    for(int i=0;i<t;i++){
        cout<<A[i]<<endl;
    }
    return 0;
}
