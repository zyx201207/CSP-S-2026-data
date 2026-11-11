#include <bits/stdc++.h>
using namespace std;
int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);
        long long d[500005],c[500005];

        long long a,b,t,ma=-99999999,p,s,sma,ts;
        cin>>a>>b;
        for(long long i=0;i<a;i++){
            cin>>d[i];
        }
        stable_sort(d,d+a);
        for(long long i=1;i<a;i++){
            c[i-1]=d[i]-d[i-1];
            //cout<<c[i-1]<<" ";
        }
        //cout<<endl;
        for(long long i=0;i<a-1;i++){
            sma=0;
            p=i;
            s=c[i];
            ts=s;
            while(p>=0&&s<=b){
                sma++;
                cout<<s<<" ";
                s+=ts;
                p--;
                s+=c[p];
                ts=s;

            }
            //cout<<sma<<endl;
            //cout<<endl;
            if(sma>ma)ma=sma;
        }
        cout<<ma+1;
        return 0;
}

