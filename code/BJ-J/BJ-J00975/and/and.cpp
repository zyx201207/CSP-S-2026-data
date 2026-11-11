#include<bits/stdc++.h>
using namespace std;
int n,m,maxnum=-1,sum,a;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    vector<int> v;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        v.push_back(a);
        maxnum=max(maxnum,a);
        if(i==1) sum=a;
        else sum=sum&a;
    }
    if(m==1) {
        cout<<maxnum;
        return 0;
    }
    if(m==n) {
        cout<<sum;
        return 0;
    }
    int nmax=-1;
    do{
        int su=v[0];
        for(int i=0;i<m;i++) su=su&v[i];
        nmax=max(nmax,su);
    }while(next_permutation(v.begin(),v.end()));
    cout<<nmax;
    fclose(stdin);
    fclose(stdout);
    return 0;
}