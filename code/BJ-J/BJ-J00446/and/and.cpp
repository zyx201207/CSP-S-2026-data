#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],c[200005],ans=0;
int d[4]={0,1,3,5};

int change(int x){
    int cnt=0,i=1;
    while(x>0){
        cnt+=x%2*i;
        x/=2;
        i*=10;
    }
    return cnt;
}


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n;i++){
        c[i]=change(a[i]);
    }

    sort(c+1,c+n+1);

    for(int i=n;i>n-m+1;i--){
        while(c[i]>0){
            int j=1;
            if(c[i]%10==1 && c[i-1]%10==1) ans+=1*j;
            else ans+=0*j;
            c[i]/=10;
            j*=10;
        }
        c[i-1]=ans;
        ans=0;
    }

    cout << c[n-m+1];
    return 0;
}

