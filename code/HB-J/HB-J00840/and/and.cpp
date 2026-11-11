#include<bits/stdc++.h>
using namespace std;
const long long MAXN=107374182;
long long m,n,a[MAXN],maxx,now;
bool flag[MAXN];

void dfs(int nm,int fi){
    int tmp=now;
    if(now==0){
        now=a[fi];
    }
    if(nm==0){
        maxx=max(maxx,now);
    }
    else{
        for(int i=fi;i<n;i++){
            /*if(flag[i]!=0){
                continue;
            }
            flag[i]=1;*/
            now&=a[i];
            dfs(nm-1,i+1);
            now=tmp;
            //flag[i]=0;
        }
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(m,0);

    cout<<maxx<<endl;

    return 0;
}
/*4 2 3 15 12 12*/
