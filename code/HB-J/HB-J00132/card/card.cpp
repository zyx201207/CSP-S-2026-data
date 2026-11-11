//wrong a lot but something true
#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500005]={};
int tj[300005]={};

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int f=0;f<n;++f){//jushu f
        int desk[500005]={};
        int e=0;
        for(int i=f;i<n;++i){//fangpai
            int flag=0;
            for(int j=0;j<e;++j){
                if(desk[j]==a[i]){
                    flag=1;
                    for(int k=j+1;k<e;++k){
                        desk[k]=0;
                    }
                    e=j+1;
                    break;
                }
            }
            if(flag==0){
                desk[e]=a[i];
                ++e;
            }
        }
        //tongji
        for(int i=0;i<e;++i){
            ++tj[desk[i]];
            //printf("get %d lun %d pai\n",f+1,desk[i]);
        }
    }
    for(int i=1;i<=m;++i){
        cout<<tj[i]<<" ";
    }
    return 0;
}
