#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
  ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    if(1==m){
        int max1=INT_MIN;
        for(int i=1;i<=n;i++){
                int c;
        cin>>c;

            max1=max(max1,c);
        }
        cout<<max1;
    }
    if(m==n){
        int m;
        cin>>m;
        for(int i=2;i<=n;i++){
                int p;
        cin>>p;
            m=(m&p);
        }
        cout<<m;
    }
    if(m==2){
            int max1=INT_MIN;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                max1=max(max1,a[i]&a[j]);
            }
        }
        cout<<max1;
    }
    if(m==n-1){
        int max1=INT_MAX;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            if(i!=1){
                int m=a[1];
            }
            else m=a[2];
            for(int j=1;j<=n;j++){
                if(j==i){
                    continue;
                }
                m=(m&a[j]);
            }
            max1=max(max1,m);
        }
        cout<<max1;
    }
    return 0;
}
