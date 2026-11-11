#include<bits/stdc++.h>
using namespace std;
const int MAXN=200001;
long int b[MAXN]={};
char d[MAXN]={};
long long a=0,num=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>b[i]>>d[i];
        a+=b[i];
    }
    long long l=0,r=n-1;
    while(l<=r){
        int e=min(b[l],b[r]);
        if(d[l]!=d[r])num+=e;
        b[l]-=e;
        b[r]-=e;
        if(b[l]==0)l++;
        if(b[r]==0)r--;
    }
    cout<<num;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
