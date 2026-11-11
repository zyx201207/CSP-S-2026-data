#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,m;
    long long a[300600]={0},b[100600]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
            int q=0;
    long long c[300550]={0};
        for(int j=i;j<=n;j++){
            int x=a[j];
            bool d=1,qq=q;
            for(int h=1;h<=q;h++){
                if(c[h]==x){
                    qq=h-1;
                    d=0;
                }
                if(d==0){
                    c[h]=0;
                }
            }
            if(!d) q=qq;
            q++;
            c[q]=x;
        }
        cout<<q<<":{";
        for(int j=1;j<=q;j++){
            b[c[j]]++;
            cout<<b[i]<<" ";
        }
        cout<<"}"<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
