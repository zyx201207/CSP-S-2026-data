#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
return x<y;}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n;
    long long m;
    cin>>n>>m;
    int a[n];
    bool p=1;
    long long w[500000]={1};
    for(int i=0;i<n;i++) {cin>>a[i];p=(a[i]==i)&&p;}
    long long maxn=1;
    if(p){//A
        for(int i=1;i<500000;i++){
            w[i]=w[i-1]+i+1;
            if(m>w[i-1]&&m<w[i]){
                cout<<i-1;
                return 0;
            }
            else if(m==w[i]){ cout<<i;
            return 0;
            }
        }


    }
    sort(a,a+n,cmp);
    long long b[n]={0};
    for(int i=1;i<n;i++){
        b[i]=a[i]-a[i-1];

    }

    for(int i=1;i<n;i++){
        long long cnt=1,mm=0;
        bool q=0;
        for(int j=i-1;j>=0;j--){
            if(q) break;


            mm+=a[i]-a[j];
            cnt++;
        if(mm>m){
                cnt--;
                q=1;
        }
        else if(mm==m) {q=1;}
        }
        //if(cnt>maxn) cout<<i<<endl;
       maxn=max(maxn,cnt);
       cnt=1;
    }

    cout<<maxn;
    return 0;
}
