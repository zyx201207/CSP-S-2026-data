#include <bits/stdc++.h>

using namespace std;

struct node{
    long long num;
    char ch;
};

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    vector<node> S;
    bool f = 1;
    long long n,ans = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        node x;
        cin>>x.num>>x.ch;
        if(x.num!=1)f = 0;
        S.push_back(x);
    }
    long long i = 0,j = S.size()-1;
    if(f){
        while(j-i>0){
            node a = S[i],b = S[j];
            if(a.ch!=b.ch)ans++;
            i++;j--;
        }
    }
    else{
        while(j-i>0){
            node a = S[i],b = S[j];
            if(a.num==b.num){
                i++;j--;
                if(a.ch!=b.ch)ans+=a.num;
            }
            else if(a.num>b.num){
                S.insert(S.begin()+i,b);
                S[++i].num = a.num - b.num;
                if(a.ch!=b.ch)ans+=b.num;
            }
            else{
                S.insert(S.begin()+j+1,a);
                S[j].num = b.num - a.num;
                i++;
                if(a.ch!=b.ch)ans+=a.num;
            }
        }
    }
    
    cout<<ans;
    return 0;
}