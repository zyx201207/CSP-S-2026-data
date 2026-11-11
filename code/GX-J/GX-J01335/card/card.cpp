#include<bits/stdc++.h>
using namespace std;
int n,m,c[300005],a[500005];
string s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=0;
    while(n-t){
        t++;
        bool bj[300005];
        for(int i=1;i<=m;i++)bj[i]=0;
        string s;
        for(int i=t;i<=n;i++){
            if(bj[a[i]]==1){
                while(s[(int)(s.size())-1]!=a[i]+'0'){
                    bj[s[(int)(s.size())-1]-'0']=0;
                    s.erase((int)(s.size())-1,1);
                }
            }
            else s+=a[i]+'0';
            bj[a[i]]=1;
        }
        for(int i=0;i<(int)(s.size());i++)c[s[i]-'0']++;
    }
    for(int i=1;i<=m;i++)cout<<c[i]<<' ';
    return 0;
}

