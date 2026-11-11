#include<bits/stdc++.h>
using namespace std;


int times[300005],a[500005];
int n,m;

void solve(int i){
    stack<int> s;
    bool tong[300005]={0};
    //cout<<"solve(i="<<i<<")\n";

    for(;i<=n;i++){
        //cout<<"i="<<i<<",a[i]="<<a[i];
        if(tong[a[i]]){

            while(s.top()!=a[i]){
                //cout<<" pop("<<s.top()<<") ";
                tong[s.top()]=0;
                s.pop();
            }
        }
        else{
            //cout<<" push(a[i])";
            s.push(a[i]);
            tong[a[i]]=1;
        }
        //cout<<"\n";
    }
    //cout<<"top()="<<s.top()<<"\n";
    for(int j=1;j<=m;j++){
        //cout<<"times["<<j<<"]+="<<tong[j]<<"\n";
        times[j]+=int(tong[j]);
    }
    return;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        solve(i);
    }
    for(int i=1;i<=m;i++){
        cout<<times[i]<<" ";
    }
    return 0;
}
