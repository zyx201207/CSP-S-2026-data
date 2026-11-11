#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int rst[500005];
int tmp1[500005];

void solve(int i){
    for(int j=0;j<n;j++){
        b[j]=0;
    }
    int tmp;
    for(int j=i;j<n;j++){
        tmp=0;
        for(int k=i;k<j;k++){
            if(a[k]==a[j]){
                tmp=1;
            }
            if(tmp){
                b[k]=1;
            }
        }
    }
}

void solve2(){
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            rst[a[i-1]]=i;
        }
    }
    rst[m]=n;
    for(int i=1;i<=m;i++){
        cout << rst[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    if(n>500){
        solve2();
        return 0;
    }
    for(int i=0;i<n;i++){
        solve(i);
        for(int j=1;j<=m;j++){
            tmp1[j]=0;
        }
        for(int j=i;j<n;j++){
            if(b[j]==0){
                //cout << "game" << i << "  card no." << j << "\n";
                tmp1[a[j]]=1;
            }
        }
        for(int i=1;i<=m;i++){
            //cout << tmp1[i] << " ";
        }
        for(int j=1;j<=m;j++){
            if(tmp1[j]){
                rst[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout << rst[i] << " ";
    }
    cout << "\n";
    return 0;
}


/*

Expectation: 6 / 100 (P4S1)

Nothing to say...

int zhongkao_score = 367 + csp_score + (6.7*left_months);

--END--@11:55

*/
