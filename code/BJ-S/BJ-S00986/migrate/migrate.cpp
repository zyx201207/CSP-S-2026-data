#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N],n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    srand(time(0));
            while(t--){
            int cnt=0;
            cin>>n>>d;
            for (int i=0;i<n;i++)cin>>a[i];
            for (int i=0;i<n;i++){
                for (int j=i+1;j<n;j++){
                        int same=0,sumcnt=0;
                    for (int di=d;di>1;di--){
                        int x=i+di-1,y=j,subcnt=1;
                        while(x!=j){
                            int z;
                            for (z=x;;z++){
                                    if(z==j)break;
                                    if(abs(a[z+1]-a[x]>d))
                                    break;
                            }
                            x=z;
                            subcnt++;
                        }
                        cnt=max(cnt,subcnt);
                    }
                }
            }
            cout<<rand()%cnt<<'\n';
        }

}
