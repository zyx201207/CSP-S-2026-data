#include<bits/stdc++.h>
using namespace std;

const int N=500010;

int vul[N],n,m,cha_zhi[N];

int Fin(){
    int mid=vul[n/2];
    int res=0;

    priority_queue<int,vector<int>,greater<int>>cha_min;


    for(int i=1;i<=n;i++){
        int w=mid-vul[i];

        cha_zhi[i]=w;

        if(w>=0){
            cha_min.push(w);
        }

    }


    while(m){
        int f=cha_min.top();
        cha_min.pop();
        if(f>=m){
            m=m-f;
            res++;
        }
        if(cha_min.empty()){
            break;
        }
    }
    return res;
}


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    scanf("%d%d",&n,&m);


    for(int i=1;i<=n;i++){
        scanf("%d",&vul[i]);
    }

    sort(vul+1,vul+n+1);

    int res=Fin();


    printf("%d",res);

    return 0;
}
