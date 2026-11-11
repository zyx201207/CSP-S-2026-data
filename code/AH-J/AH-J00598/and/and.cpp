#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[200001];
    int ans = 0;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>a[i]
    }
    for(int i = 0;i<n;i++){
        if(a[i]>ans){
            ans = a[i];
        }
    }
    if(m = 2){
        ans = 0;
        for(int i = 0;i<n;i++){
            int e = 0;
            int b[30];
            int d = 0;
            int c = a[i];
            while(c!=0){
                if(c%2==0){
                    d++;
                    c = c/2;
                }
                else{
                    b[d] = 1;
                    d++;
                    c = (c-1)/2;
                }
            }
            for(int j = d;j>=0;j--){
                e*=10;
                e+=b[j]
            }
            a[i] = e;
        }
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int b = a[i]+a[j];
                int c[30];
                for(int k = 0;k<21;k++){
                    if(b%10==2)c[k] = b%10;
                    b-=b%10;
                    b/=10;
                }
                for(int k = 20;k>=0;k--){
                    b*=10;
                    b+=c[k];
                }
                if(b>ans)ans = b;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
