#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    int a;
    cin>>a;
    int b;
    cin>>b;
    int z[a];
    int c[a];
    for(int i=0;i<a;i++){
        cin>>c[i];
    }

    int e[a];
    int f[a]={0};
    int x=-1;

     for(int j=0;j<a;j++){
            int d=0;
      for(int i=0;i<a;i++){
            int h=0;
            for(int w=0;w<a;w++){
               if(z[w]==i){
                h++;
            }
            }
          if(h>0)
          continue;
       if(d<c[i]){
        d=c[i];
        x=i;
       }
    }

    z[j]=x;
     f[j]=d;
    }
        cout<<f[b-1];
        return 0;
}
