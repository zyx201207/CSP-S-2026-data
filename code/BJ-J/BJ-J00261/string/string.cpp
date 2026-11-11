#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int l=1,n;
pair<long long,string> s[maxn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string last;
    for(int i=1;i<=n;i++){
        long long x;
        string y;
        cin>>x>>y;
        if(i!=1&&y==last){
            s[l-1].first+=x;
        }
        else{
            s[l].first=x;
            s[l++].second=y;
        }
        last=y;
    }
    //cout<<"\n";
    //for(int i=1;i<l;i++){
    //   cout<<s[i].first<<" "<<s[i].second<<"\n";
    //}
    for(int i=1;i<l/2;i++){
        if(s[i].second.size()!=s[l-i].second.size()){
            break;
        }else{
            bool flag=true;
            for(int j=0;j<s[i].second.size();j++){
                if(s[i].second.size()!=s[l-i].second.size()){
                    flag=false;
                    break;
                }
            }

            if(flag){
                long long x=min(s[i].first,s[l-i].first);
                s[i].first-=x;
                s[l-i].first-=x;
                if(s[i].first!=0||s[l-i].first!=0){
                    break;
                }
            }

        }
    }

    //cout<<"\n";
    //for(int i=1;i<l;i++){
    //   cout<<s[i].first<<" "<<s[i].second<<"\n";
    //}
    //cout<<"\n";

    string str="";

    for(int i=1;i<l;i++){
        while(s[i].first--){
            str+=s[i].second;
        }
    }
    //long long cnt=0;
    // for(int i=1;i<l;i++){
    //     cnt+=s[i].first;
    // }

    long long cnt=0,l=str.size();
    for(int i=0;i<l/2;i++){
        if(str[l-i-1]!=str[i])
            cnt++;
    }
    cout<<cnt;

    return 0;
}