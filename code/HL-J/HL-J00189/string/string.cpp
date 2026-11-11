#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long a;
char c,ic;
deque <char>q;
int v=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){

        cin>>a>>c;

        if(c==ic&&v==1&&i==n-1){
            cout<<0;
            return 0;
        }else if(c!=ic&&i!=0){
            v=0;
        }
        for(int i=0;i<a;i++){
            q.push_back(c);
        }
        char ic=c;
    }

    for(int i=0;i<q.size();i++){
        char f=q.front();
        char e=q.back();
        if(f!=e){
            ans++;
        }
        q.pop_front();
        q.pop_back();

    }
    cout<<ans;

    return 0;
}
