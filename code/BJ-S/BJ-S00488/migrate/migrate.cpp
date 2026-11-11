#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[2000005],b[2000005][2],num,ans;
void f(long long l,long long r){
    b[0][0] = l-1,b[0][1] = l-1;
    b[num][0] = r,b[num][1] = r;
    for(long long i = 1;i<num;i++){
        ans+=(b[i][0]-b[i-1][0])*(b[i+1][1]-b[i][1]);
    }
}
int main(){
    freopen("r","migrate.in",stdin);
    freopen("w","migrate.out",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        num = 1;
        ans = 0;
        long long l = 0;
        for(long long i = 0;i<n;i++){
            cin>>a[i];
            if(num==1){
                if(((a[i-1]-a[i-4])>d)&&(a[i-1]-a[i-3]<=d)&&(a[i-2]-a[i-4]<=d)){
                    b[num][0] = i-4,b[num++][1] = i-1;
                }
            }else if(a[i-1]-a[i-4]>d&&(a[i-1]-a[i-3]<=d)&&(a[i-2]-a[i-4]<=d)){
                b[num][0] = i-4,b[num++][1] = i-1;
            }
            if(a[i]-a[i-1]>d){
                if(a[i-1]-a[i-4]<=d&&a[i-1]-a[i-5]>d){
                    b[num][0] = i-4,b[num++][1] = i-1;
                }
                f(l,i);
                l = i;
                num = 1;
            }
        }
        if(n>=5){
            if(a[n-1]-a[n-4]>d&&a[n-2]-a[n-5]>d&&(a[n-1]-a[n-3]<=d)&&(a[n-2]-a[n-4]<=d)){
                b[num][0] = n-4,b[num++][1] = n-1;
            }
        }else{
            if(a[n-1]-a[n-4]>d&&(a[n-1]-a[n-3]<=d)&&(a[n-2]-a[n-4]<=d)){
                b[num][0] = n-4,b[num++][1] = n-1;
            }
        }
        if(num!=1){
            f(l,n);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
