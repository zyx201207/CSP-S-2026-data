#include<bits/stdc++.h>
using namespace std;
//crystal
long long n,m,flag,maxn;
int a[500005],cf[500005],b[500005];

bool cmp(int a,int b){
    if(flag-a<0)a-=10000000000;
    if(flag-b<0)b-=10000000000;
    return flag-a<flag-b;
}

void out(int pyl,int c){
    for(int i=1;i<=n;i++){
        cout<<a[i+pyl]<<" ";
        if(i==c-pyl)cout<<"||||||||\n\n\n";
    }
    cout<<"\n";
    return;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }

    sort(b+1,b+n+1);

    /*for(int i=1;i<=n;i++){
        cf[i]=a[i]-a[i-1];
    }

    int l=1,r=1;
    while(r<=n){

    }*/
    flag=b[n];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        a[i+n]=a[i];

    int mi=b[2],ma=b[n-1];
    for(int i=1;i<=n;i++){
        if(b[i]==b[i+1])continue;
        flag=b[i];
        long long pyl=n-i;
        long long s=0,c=pyl;
        while((s+flag-a[c+1])<=m&&c<=n+pyl-1){
            if(flag-a[c+1]<0)break;
            c++;
            s+=flag-a[c];
            //cout<<"now c="<<c<<",s="<<s<<".\n";
        }
        //if(flag==52113)
            //out(pyl,c);
        //cout<<"flag="<<flag<<",s="<<s<<",c="<<c-pyl<<".\n";
        maxn=max(maxn,c-pyl);
    }

    cout<<maxn;

    return 0;
}
