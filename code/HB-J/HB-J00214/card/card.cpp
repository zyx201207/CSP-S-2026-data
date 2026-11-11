/*
CSP-J2 2026 RP++
D 157min 48pts.
*/
#include<bits/stdc++.h>
using namespace std;
const int maxN=2e5+10;
int n,m,a[maxN],cnt[maxN];
bool in[maxN];
stack<int> st;
int main(){
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(false);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(in[a[j]]){
                while(!st.empty()&&st.top()!=a[j]) {in[st.top()]=0;st.pop();};
                in[a[j]]=0;
                st.pop();
            }
            in[a[j]]=1;
            st.push(a[j]);
        }
        while(!st.empty()){
            if(in[st.top()]) cnt[st.top()]++;
            in[st.top()]=0;
            // cout<<i<<" "<<st.top()<<"\n";
            st.pop();
        }
    }
    for(int i=1;i<m;i++) cout<<cnt[i]<<" ";
    cout<<cnt[m]<<"\n";
    return 0;
}

/*
jin nian chu er le,
ye xu shi chu zhong zui hou yi nian can jia CCF-CSP-SJ le.
ren zai hua zhong shi da yi fu zhong,
ban li de whk ya li ye ting da de.
zong er yan zhi hai shi xi wang neng zai OI&&whk shang you suo jian shu ba!

CSP-SJ2 2026 RP++.

p.s. bu qing chu HBOI you mei you qi pa da shang ei...mei you jiu rang wo lai zuo ba!
shun bian tui luogu uid:942153
hu guan lai
gan xie HBoi,HSYoi,CCF-Noi...

303 points yi han li chang~
*/