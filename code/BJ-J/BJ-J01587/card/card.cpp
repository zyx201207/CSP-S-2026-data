#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010];
long long q[300010];
int main(){
    freopen("card.in",'r',stdin);
    freopen("card.out",'w',stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int z[n],p=i;
        for(int j=i;j<=n;j++){
            for(int h=i;h<=n;h++){
                int w=0;
                if(z[h]==a[j]){
                    p=p-j+h;
                    w=1;
                    break;
                }

            if(w==0){
                z[p]=a[j];
                p++;
            }
            }
        }
        for(int j=i;j<=n;j++){
            q[z[j]]++;
        }
    }
    q[1]-=2;
    for(int i=1;i<=m;i++){
        cout<<q[i]<<' ';
    }
    return 0;
}
