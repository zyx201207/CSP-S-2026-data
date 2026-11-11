#include<bits/stdc++.h>

using namespace std;

int n,m;
int lst[500005];
int nlst[500005];
int la[500005];
int ans[500005];
vector<int> v[30005];
int f1=1,f2=1;

void solve1(){
    for(int i=1;i<=n;i++){
        v[lst[i]].push_back(i);
    }

    vector<int> now;
    for(int k=1;k<=n;k++){
        now.clear();
        for(int i=k;i<=n;i++){
            if(v[lst[i]][v[lst[i]].size()-1]==i){//have not the second one
                now.push_back(lst[i]);
            }
            else{
                int p=lower_bound(v[lst[i]].begin(),v[lst[i]].end(),i)-v[lst[i]].begin();
                i=v[lst[i]][p+1]-1;
            }
        }

        for(int x:now){
            ans[x]++;
            //cout<<x<<" ";
        }
        //cout<<'\n';
    }
}

void solve2(){
    for(int i=1;i<=n;i++){
        la[lst[i]]=i;
    }
}

void solve3(){
    int nw=0;
    vector<int> sum;
    for(int i=1;i<=n;i++){
        int j=i;
        for(j=i;j<=n;j++){
            if(lst[j]!=lst[i]){
                break;
            }
        }
        j--;
        sum.push_back(j-i+1);
        //<<j<<":"<<j-i+1<<'\n';
        nlst[++nw]=lst[i];
        i=j;
    }

    for(int i=1;i<=nw;i++){
        lst[i]=nlst[i];
    }
    n=nw;

    for(int i=1;i<=n;i++){
        v[lst[i]].push_back(i);
    }

    vector<int> now;
    for(int k=1;k<=n;k++){
        now.clear();
        for(int i=k;i<=n;i++){
            if(v[lst[i]][v[lst[i]].size()-1]==i){//have not the second one
                now.push_back(lst[i]);
            }
            else{
                int p=lower_bound(v[lst[i]].begin(),v[lst[i]].end(),i)-v[lst[i]].begin();
                i=v[lst[i]][p+1]-1;
            }
        }

        for(int x:now){
            ans[x]+=sum[k-1];
        }
        //cout<<sum[k]<<" ";
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>lst[i];
        if(i>=2 && lst[i-1]>lst[i]){
            f1=0;
        }
        if(lst[i-1]!=lst[i]){
            cnt++;
        }
    }
    if(cnt>4999){
        f2=0;
    }

    if(n<=5000){
        solve1();
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
    }
    else if(f1){
        solve2();
        for(int i=1;i<=m;i++){
            cout<<la[i]<<" ";
        }
    }
    else{
        solve3();
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
    }

    return 0;
}
