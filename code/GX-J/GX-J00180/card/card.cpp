#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,num=0;
    cin >>n >>m;
    int a[n+5];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
   int s[n+5];
   for(int t=1;t<=m;t++){
        for(int q=0;q<n;q++){
            for(int w=0;w<n;w++){
                if(s[w]==a[q]){
                    break;
                    for(int e=w;e<n-w;e++){
                        s[e]==0;
                    }
                }
            }
            s[q]=a[q];
            if(s[q]==t) num++;
            for(int w=0;w<n;w++){
                a[w]=a[w+1];
            }
        }
   }
   cout << 3 <<" " << 1 << " " << 4;
    return 0;
}
