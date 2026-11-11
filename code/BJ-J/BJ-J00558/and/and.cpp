#include<bits/stdc++.h>
using namespace std;
int quyi(int x){
    int i=0,a[10000],cnt=0;
    while(x>0){
        if(x%2==1){
            cnt++;
        }
        x=x/2;
        i++;
    }
    return cnt;
}
int yu(int x,int y){
    int c[100000]={0},d[100000]={0},ans[100000],p[100000];
    int i=0;
    while(x>0){
        c[i]=x%2;
        x=x/2;
        i++;
    }
    int temp;
    for(int k=0;k<i;k++){
        temp=c[k];
        c[k]=c[i-k-1];
        c[i-k-1]=temp;
    }
    int maxx=i;
    i=0;
    while(y>0){
        d[i]=y%2;
        y=y/2;
        i++;
    }
    for(int k=0;k<i;k++){
        temp=d[k];
        d[k]=d[i-k-1];
        d[i-k-1]=temp;
    }
    if(maxx<i)
        maxx=i;
    for(i=0;i<maxx;i++){
        if(c[i]==1&&d[i]==1)
            ans[i]=1;
        else
            ans[i]=0;
    }
    int tw=1,bn=0,j=0;
    while(j<maxx){
        bn=bn+ans[j]*tw;
        tw*=2;
        j++;
    }
    return bn;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[200000],p[200000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        int ma=-1;
        for(int i=0;i<n;i++){
            if(a[i]>ma)
                ma=a[i];
        }
        cout<<ma<<"\n";
        return 0;
    }
    else if(m==2){
        int max=-1;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int temp=yu(a[i],a[j]);
                if(temp>max)
                    max=temp;
            }
        }
        cout<<max<<"\n";
        return 0;
    }\
    else{
        for(int i=0;i<n;i++){
            p[i]=quyi(a[i]);
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(p[i]<p[j]){
                    int temp=a[i];
                    a[i]=a[j];
                    a[j]=a[i];
                }
            }
        }
        for(int i=0;i<m-1;i++){
            a[i+1]=yu(a[i],a[i+1]);
        }
        cout<<a[m-1];
        return 0;
    }
    return 0;
}
