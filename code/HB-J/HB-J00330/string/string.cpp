#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
long long c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        cnt+=a[i];
        c[i]=c[i-1]+a[i];
    }
    long long ans=0,wh=0;
    if(cnt%2==1){
        ans=(cnt+1)/2;
        int yin=n;
        for(int i=1;i<n;i++){
            if(c[i]<=ans&&c[i+1]>=ans){
                yin=i;
                break;
            }
        }
        long long ll=1,zzw=cnt;
        int li=1,ri=n;
        while(li<ri){
            if(c[li]-ll+1<=zzw-c[ri-1]){
                wh+=c[li]-ll+1;
                zzw=c[li]-ll+1;
                li++;
                ll=c[li-1];
            }else{
                wh+=zzw-c[ri-1];
                ll+=zzw-c[ri-1];
                ri--;
                zzw=c[ri];
            }
        }
    }
    cout<<wh;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
