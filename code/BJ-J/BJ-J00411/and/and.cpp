#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r","stdin");
    freopen("and.out","w","stdout");
    int a[200005];
    int jun[200005];
    int r[200005];
    int l[200005];
    int jm[200005];
    int n,m,x=-1,y=100000,d=0,e=1,vb;
    cin>>n>>m;
    for(int i=1;i<=n;i++){

        cin>>vb;
        a[i]=vb;
    }
    for(int q=1;q<=m;q++){
        for(int j=1;j<=n;j++){
            if(a[j]>x){
                x=a[j];
                d=j;
            }
        }

        a[d]=0;
        jun[q]=x;
        x=-1;
        while(true){
            if(jun[q]==0){
                break;
            }
            r[e]=jun[q]%2;
            jun[q]=jun[q]/2;
        }
        for(int s=1;s<=r.size();s++){
            if(q==1){
                for(int pu=1;pu<=r.size;pu++){
                    l[pu]=r[pu];
                }
                continue;
            }
            if(r[s]==l[s]){
                l[s]=1;
            }
            else(){
                l[s]=0;
            }
        }
    }
    int cc=l.size(),md=0,sum=0,z=1;
    for(int h=l.size();h>=1;h--){
        md=cc-h+1;
        jm[h]=l[md];
        if(jm[h]==1){
            if(md==1){
                sum+=1;
            }
            for(int lk=1;lk<md;lk++){
                if(md==1){
                    continue;
                }
                z=z*2;

            }
            sum+=z;
            z=1;
        }
    }
    cout<<sum;
    return 0;


}
