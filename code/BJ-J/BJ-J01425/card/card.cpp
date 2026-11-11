#include <iostream>
#include <algorithm>
using namespace std;
int a[100005],n,m,ans[1000005],shu[1000005];
bool check(int b,int wei){
    for(int i=1;i<wei;i++){
        if(b==a[i]){
            return false;
        }
    }
    return true;
}
void ju(int qi){
    string s;
    int wei[100005],w=0;
    bool y[100005]={0};

    for(int i=qi;i<=n;i++){
        if(y[a[i]]==1){
            for(int j=wei[a[i]];j<s.size();j++){
                y[s[j]-'0']=0;
            }
            s.substr(0,wei[a[i]]);
            y[a[i]]=1;
        }
        else{
            s+=a[i]+'0';
            y[a[i]]=1;
            wei[a[i]]=w;
            w++;
        }

    }
    for(int i=0;i<m;i++){
        if(y[shu[i]]){
            ans[shu[i]]++;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int m_i=1;
    cin>>a[1];
    shu[0]=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(check(a[i],i)){
            shu[m_i]=a[i];
            m_i++;
        }
    }
    for(int i=1;i<=n;i++){
        ju(i);
    }
    sort(shu,shu+m);
    for(int i=0;i<m;i++){
        cout<<ans[shu[i]]<<" ";
    }
}