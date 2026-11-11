#include<bits/stdc++.h>
using namespace std;
int ans=0;
int a[10000];
int n;
int m;
int nw=0;
void renyi(int p,int sheng,int all,int c[],int num){//num is houmuch num we choses

    if(sheng<=0){
        return;
    }
    if(all<=m){
        nw=max(num,nw);
    }
    for(int i=p;i<sheng;i++){//
        renyi(i+1,sheng-1,all+c[i],c,num+1);//
    }
}

int pan(int maxx){
    int b[10000];
    int c[10000];
    for(int i=0;i<n;i++){
        b[i]=a[i]-maxx;//2
    }
    int ad=0;
    int j=0;
    for(int i=0;i<n;i++){
        if(b[i]<0){//
            continue;
        }
        c[j]=b[i];
        ad++;
        j++;
    }
    renyi(0,ad,0,c,1);//
    ans=max(ans,nw);

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        pan(a[i]);
        //cout<<"pan[i]="<<a[i]<<endl;
    }
    cout<<ans;
}
