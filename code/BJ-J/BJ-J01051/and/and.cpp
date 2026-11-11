#include <bits/stdc++.h>
using namespace std;
//test:
const int N = 2e5+7;
int n,m,a[N],b[N][35];
vector<int> f[N];

void to_bit(int x,int index){
    int p = (1<<30);
    for(int i = 1;i<=32;i++){
        if(x>=p){
            b[index][i] = 1;
            x-=p;
        }
        p/=2;
    }
    return;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        f[0].push_back(i);
        to_bit(a[i],i);
/*        for(int j = 26;j<=32;j++){
            cout << b[i][j];
        }
        cout << endl;*/
    }
    for(int i = 1;i<=32;i++){
        vector<int> p = f[i-1];
        while(!p.empty()){
            int x = p.back();
            p.pop_back();
            if(b[x][i])f[i].push_back(x);
        }
        if(f[i].size()<m)f[i] = f[i-1];
/*        if(i<=25)continue;
        for(int j = f[i].size()-1;j>=0;j--){
            cout << f[i][j] << " ";
        }
        cout << endl;*/
    }
    int ans = a[f[32][0]];
    for(int i = 1;i<f[32].size();i++){
        ans&=a[f[32][i]];
    }
    printf("%d",ans);
    return 0;
}