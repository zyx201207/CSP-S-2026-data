#include<bits/stdc++.h>
using namespace std;
pair<long long,char>a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        if(a[i].second==a[i-1].second){
            a[i-1].first+=a[i].first;
            n--;
            i--;
        }
    }
    long long s=1,e=n,fs=0,fe=0;
    bool p=1;long long cs=0;
    while(p){
        fs=a[s].first;
        fe=a[e].first;
        if(a[s].second!=a[e].second){
            if(fs<fe){
                s++;
                cs+=fs;
                a[e].first-=fs;
            }
            if(fs>fe){
                e--;
                cs+=fe;
                a[s].first-=fe;
            }
             if(fs==fe){
                e--;
                s++;
               cs+=fs;
            }
            if(s>=e){
                break;
            }
        }else{
            if(fs<fe){
                s++;
                a[e].first-=fs;
            }
            if(fs>fe){
                e--;
                a[s].first-=fe;
            }
             if(fs==fe){
                e--;
                s++;

            }
            if(s>=e){
                break;
            }
        }

    }
    cout<<cs;
    return 0;
}

