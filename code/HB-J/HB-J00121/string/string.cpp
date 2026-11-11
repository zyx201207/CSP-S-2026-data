#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N=2e5+500;
LL n,a[N],ans=0;
char c[N];
vector<LL>d;
vector<LL>t;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    LL st=0;
    d.push_back(0);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        //d.push_back(st+1);
        d.push_back(st+a[i]);
        st+=a[i];
    }
    st=0;
    for(int i=n;i>=1;i--){
        d.push_back(st+a[i]);
        st+=a[i];
    }
    if(st%2==0){
        d.push_back(st/2);
        //d.push_back((st/2)+1);
        sort(d.begin(),d.end());
        for(int x=0;x<d.size();x++){
            if(x==0){
                t.push_back(d[x]);
            }else{
                if(d[x]!=d[x-1]){
                    t.push_back(d[x]);
                }
            }
        }
        char col1[N*2];//col[i] -> [t[i]+1,t[i+1]],0-base
        LL idx=0,ed=0;
        for(int x=1;x<=n;x++){
            ed+=a[x];
            while(t[idx+1]<=ed){
                col1[idx]=c[x];
                idx++;
                if(idx==t.size()-1){
                    break;
                }
            }
        }
        char col2[N*2];//col[i] -> [t[i]+1,t[i+1]],0-base
        idx=0,ed=0;
        for(int x=n;x>=1;x--){
            ed+=a[x];
            while(t[idx+1]<=ed){
                col2[idx]=c[x];
                idx++;
                if(idx==t.size()-1){
                    break;
                }
            }
        }
        for(int x=0;x<t.size()-1;x++){
            //cout<<t[x]+1<<"->"<<t[x+1]<<' '<<col1[x]<<endl;
        }
        for(int x=0;x<t.size()-1;x++){
            //cout<<t[x]+1<<"->"<<t[x+1]<<' '<<col2[x]<<endl;
        }
        for(int x=0;x<t.size()-1;x++){
            if(col1[x]!=col2[x]){
                ans+=t[x+1]-t[x];
            }
        }
        cout<<ans/2<<endl;
    }else{
        d.push_back(st/2);
        d.push_back((st/2)+1);
        sort(d.begin(),d.end());
        for(int x=0;x<d.size();x++){
            if(x==0){
                t.push_back(d[x]);
            }else{
                if(d[x]!=d[x-1]){
                    t.push_back(d[x]);
                }
            }
        }
        char col1[N*2];//col[i] -> [t[i]+1,t[i+1]],0-base
        LL idx=0,ed=0;
        for(int x=1;x<=n;x++){
            ed+=a[x];
            while(t[idx+1]<=ed){
                col1[idx]=c[x];
                idx++;
                if(idx==t.size()-1){
                    break;
                }
            }
        }
        char col2[N*2];//col[i] -> [t[i]+1,t[i+1]],0-base
        idx=0,ed=0;
        for(int x=n;x>=1;x--){
            ed+=a[x];
            while(t[idx+1]<=ed){
                col2[idx]=c[x];
                idx++;
                if(idx==t.size()-1){
                    break;
                }
            }
        }
        for(int x=0;x<t.size()-1;x++){
            //cout<<t[x]+1<<"->"<<t[x+1]<<' '<<col1[x]<<endl;
        }
        for(int x=0;x<t.size()-1;x++){
            //cout<<t[x]+1<<"->"<<t[x+1]<<' '<<col2[x]<<endl;
        }
        for(int x=0;x<t.size()-1;x++){
            if(col1[x]!=col2[x]){
                ans+=t[x+1]-t[x];
            }
        }
        cout<<ans/2<<endl;
    }
}

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

4
3 a
4 b
3 c
8 a

aaabbbbcc caaaaaaaa
aaaaaaaac ccbbbbccc
*/