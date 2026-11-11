#include<bits/stdc++.h>
using namespace std;
#define int long long
struct str{
    int a;
    char c;
}s[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }
    vector<str>v;
    for(int i=1;i<=n;i++){
        v.push_back(s[i]);
        while(s[i+1].c==s[i].c){
            i++;
            v[v.size()-1].a+=s[i].a;
        }
    }
    int l=0,r=v.size()-1;
    int res=0;
    while(l<r){
        int lres=v[l].a,rres=v[r].a;
        if(v[l].c==v[r].c){
            if(lres>rres){
                v[l].a-=rres;
                r--;
            }else if(lres<rres){
                v[r].a-=lres;
                l++;
            }else{
                l++;
                r--;
            }
        }else{
            if(lres>rres){
                v[l].a-=rres;
                res+=rres;
                r--;
            }else if(lres<rres){
                v[r].a-=lres;
                res+=lres;
                l++;
            }else{
                res+=lres;
                l++;
                r--;
            }
        }
    }
    cout<<res;
    return 0;
}