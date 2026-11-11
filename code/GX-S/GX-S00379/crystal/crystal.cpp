#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    vector<int>p(n,0);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    sort(p.begin(),p.end());

    for(int i=0;i<n;i++){

        for(int j=0;j<=i;j++){
            int cnt=0;
            cnt+=p[i]-p[j];
            if(cnt<=m)p[j]+=cnt;
            else p[j]+=m;
            m-=cnt;
            if(m<=0)break;
        }
        if(m<=0)break;
    }
    int t=1;
    for(int i=0;i<n;i++){
        if(p[0]==p[i+1])t++;
    }
    cout<<t;
    return 0;
}
