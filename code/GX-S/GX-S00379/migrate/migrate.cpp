#include<iostream>
#include<vector>

using namespace std;

int n=0,d=0;
vector<int>q(0);
vector<int>p(0);
int sum;

void dfs(int a){
    for(int i=0;i<n;i++){
        if(p[0]-p[i+1]<=d&&i+1<n)dfs(i+1);
    }
    sum++;
}

void migrate(){
    n=0,d=0;
    cin>>n>>d;



    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        p.push_back(t);
    }
    dfs(0);
    if(p[n-1]-p[0]<=d)cout<<0;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while(t--)migrate();
    return 0;
}
