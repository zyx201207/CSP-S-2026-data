// this is certainly a big simulation problem
// however, due to insufficient time, i am unable to solve it
// therefor, i chose to give it up - 0 score

// redirected? yes
// undebugged? yes
// but how? it can't even be compiled

#include<iostream>
#include<cstdio>
#include<cstring>
#include<unordered_set>
#include<unordered_map>
#include<list>
using namespace std;

//#define debug // redirected when off

const size_t MAXN=5e5+3,MAXM=3e5+3;
int a[MAXN];
list<int> cards;
unordered_map<int,list<int>::iterator> pointPos;
unordered_map<int,int> cnt;

int main(){
    #ifndef debug
    freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif // debug
    freopen("card.in","r",stdin);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    // simulate nth round of game
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            // card with point a[j] is not on the table
            if(pointPos.find(a[j])==pointPos.end()){
                cards.push_back(a[j]);
                pointPos[a[j]]=prev(cards.end());
            }
            // on the table
            else{
                auto pointIt=pointPos[a[j]];
                for(auto it=cards.rbegin();it!=cards.rend();++it){
                    cards.erase(static_cast<list<int>::iterator>(it));
                    if(it==pointIt)break;
                }
            }
        }

        for(auto it=cards.begin();it!=cards.end();++it){
            if(cnt.find(*it)==cnt.end())cnt[*it]=1;
            else ++cnt[*it];
        }
    }

    for(int i=1;i<=m;++i){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
