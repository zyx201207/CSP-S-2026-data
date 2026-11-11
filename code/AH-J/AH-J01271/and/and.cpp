#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
long long mx,sum;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum=a[1];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=m;k++){
                sum=a[i]&a[j];
                mx=max(mx,sum);
            }
        }
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
