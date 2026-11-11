#include<bits/stdc++.h>
using namespace std;
int cnt[100];
vector<int>a;
int res=0;
int n,m;
void find(int pw){
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<a.size();i++){
        int num=a[i],now=0;
        while(num>0){
            if(num&1){
                cnt[now]++;
            }
            now++;
            num>>=1;
        }
    }
    for(int i=pw;i>=0;i--){
        if(cnt[i]<m){
            continue;
        }
        int p=pow(2,i);
        res+=p;
        vector<int>neo;
        for(int i=0;i<a.size();i++){
            if(a[i]&p){
                neo.push_back(a[i]);
            }
        }
        a=neo;
        find(i-1);
        break;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        a.push_back(x);
    }
    find(30);
    cout<<res;
    return 0;
}