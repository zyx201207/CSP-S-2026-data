#include<bits/stdc++.h>
using namespace std;
long long n,ant[200005],b,ans;
char a;
map<long long,pair<char,long long>>mp;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b>>a;

        ant[i]=b+ant[i-1];
        //cout<<ant[i]<<endl;
        mp[i].first=a;
        mp[i].second=b;
    }//cout<<ant[n]<<'c';
    auto t=lower_bound(ant+1,ant+n+1,(ant[n]+1)/2);
    int ls=t-ant;
    if(ant[n]%2!=0){

        //cout<<0;
        mp[ls].second--;
       // cout<<mp[ls].second;
        for(int i=ls;i<=n;i++)ant[i]--;
        t=lower_bound(ant+1,ant+n+1,(ant[n]+1)/2);
        ls=t-ant;
    }//cout<<ls<<endl;

    int len=mp.size();
    for(int i=ls;i>0;i--){
            //cout<<1;
        if(mp.size()<=1)break;
        if(mp[i].first!=mp[mp.size()-i+1].first){
            if(mp[i].second==mp[mp.size()-i+1].second){
                ans+=mp[i].second;
                //cout<<mp[i].second<<' '<<ans;
                //i++;
            }
            else if(mp[i].second<mp[mp.size()-i+1].second){
                ans+=mp[i].second;
                mp[mp.size()-i+1].second-=mp[i].second;
                mp.erase(i);
                i++;
            }
            else{
                ans+=mp[mp.size()-i+1].second;
                //cout<<mp[mp.size()-i-1].second;
                mp[i].second-=mp[mp.size()-i+1].second;
                mp.erase(mp.size()-i+1);
                i++;
            }
        }
        else{
            if(mp[i].second==mp[mp.size()-i+1].second){

                //i++;
            }
            else if(mp[i].second<mp[mp.size()-i+1].second){
                    mp[mp.size()-i+1].second-=mp[i].second;
                mp.erase(i);
                i++;
            }
            else{
                mp[i].second-=mp[mp.size()-i+1].second;
                mp.erase(mp.size()-i+1);
                i++;
            }
        }
    }cout<<ans;
    return 0;
}
/*

*/
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000010 b
1000000000 b
1000000000 b

3000000000
*/
