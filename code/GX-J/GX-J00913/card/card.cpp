#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int b[10000000];
int main(){
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m,c;
    cin>>n>>m;
    for(int i =0;i<n;i++){
        int q =0;
        cin>>q;
        a[i] = q;
    }
    for(int i=1;i<=m;i++){
        int mun = 0;
        int w = 0;
        c = n;
        for(int k = 0;k<n;k++){
            int s = 0;
            b[s] = a[k];
            s+=1;
            for(int l = 0;l<=s;l++){
                if (c<=0){
                    for(int h = 0;h<c;h++){
                        if(b[h]==i){
                            mun+=1;
                            w+=1;
                            break;
                    break;
                if(k==b[l]){
                    for(int j = 0;j<n;j++){
                        b[j]=0;
                        s=0;
                        c-=1;
                    }

                        }
                        }
                    }
                }
            }
        }
        cout<<mun;
    }
    return 0;
}
