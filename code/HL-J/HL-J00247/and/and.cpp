#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx,an;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[0];
    an=a[0];
    maxx=max(maxx,a[0]);
    for(int i=0;i<n;i++){
        cin>>a[i];
        an&=a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1)cout<<maxx;
    if(m==2){
        maxx=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxx=max(maxx,a[i]&a[j]);
                cout<<a[i]<<" "<<a[j]<<" "<<maxx<<"\n";
            }
        }
        cout<<maxx;
    }
    if(m==n)cout<<an;
    if(m==n-1){
        maxx=-1;
        an=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i)continue;
                if(i==0&&j==1||j==0){
                    an=a[j];
                    continue;
                }
                an&=a[j];
            }
            maxx=an;
        }
        cout<<maxx;
    }
    return 0;
}
