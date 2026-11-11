#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n;
    int a[1001];
    char c[1001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    char b[100001];
    int m=0;
    for(int i=0;i<n;i++){
        for(int j=m;j<a[i]+m;j++){
            b[j]=c[i];
        }
        m+=a[i];
    }
    char w[10001];
    char v[10001];
    int s=0;
    if(m%2==0){
        for(int i=0;i<m/2;i++){
            w[i]=b[i];
        }
        for(int i=m/2-1;i<m;i++){
            v[s]=b[i];
            s++;
        }
    }
    else{
        for(int i=0;i<m/2;i++){
            w[i]=b[i];
        }
        for(int i=m/2+1;i<m;i++){
            v[s]=b[i];
            s++;
        }
    }
    int u=0;
    for(int i=0;i<s;i++){
        if(v[i]!=w[i]){
            u+=1;
        }
    }
    cout<<u;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
