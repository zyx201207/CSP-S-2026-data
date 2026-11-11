#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005],answer=0,maxai=0;
//pianfenfa,yuji20'
long long yihuo(long long x,long long y){
    int x1=x,y1=y,q=0,p=0,lenx,leny,ans=0;
    bool lx[35],ly[35],lans[35];
    while(x1/2>0){
        x1/=2;
        q++;
    }
    x1=x;
    lenx=q;
    while(x1>0){
        if(x1>=2^q){
            x1-=2^q;
            lx[q]=1;
        }
        else{
            lx[q]=0;
        }
        q-=1;
    }
    while(y1/2>0){
        y1/=2;
        p++;
    }
    y1=y;
    leny=p;
    while(y1>0){
        if(y1>=2^p){
            y1-=2^p;
            ly[p]=1;
        }
        else{
            ly[p]=0;
        }
        p-=1;
    }
    for(int i=0;i<=max(lenx,leny);i++){
        lans[i]=(lx[i] and ly[i]);
    }
    for(int i=0;i<=max(lenx,leny);i++){
        ans+=(2^i)*lans[i];
    }
    return ans;

}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool o=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxai=max(maxai,a[i]);
        if(a[i]!=i-1)o=0;
    }
    sort(a+1,a+n+1);
    answer=a[n-m+1];//13
    if(o==1){//14~15
        if(m>2 and m<=n/2){
            answer = n/2;
        }
        if(m>n/2){
            answer =0;
        }
    }

    if(m==2){//8~10
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                //answer = max(yihuo(a[i]),yihuo(a[j]));
                answer=max(min(a[i],a[j]),answer);
            }
        }
    }

    if(m==1){//6
        answer=maxai;
    }
    //if(n==m){
    //yigeceshidian
    //}

    cout<<answer;
    fclose(stdin);
    fclose(stdout);
    return 0;
}