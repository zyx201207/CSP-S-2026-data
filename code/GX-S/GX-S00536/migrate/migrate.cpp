#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
int main(){
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++){
        int n,d,tmp=0;
        queue<int>q;
        cin>>n>>d;
        memset(x,0,sizeof(x));
        for(int j=0;j<n;j++){
            cin>>x[j];
        }
        q.push(x[0]);
        while(!q.empty()){
            int tmp=q.front();
            for(int j=1;j<=d;j++){
                int xx=x[tmp]+j;
                for(int k=tmp;k<=i;k++){

                }
            }
        }
    }
    cout<<"bu hui xie QAQ";
    return 0;
}
