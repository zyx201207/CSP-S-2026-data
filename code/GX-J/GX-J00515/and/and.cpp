#include<bits/stdc++.h>
using namespace std;
int n;
int m;
long long a[200005];
bool cmp(int a,int b){
    return a>b;
}

int main(){

    freopen("ans.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1,cmp);
    if(m<=200005&&n<=200005){
    for(int i=1;i<m;i++){

        for(int j=2;j<=n-i+1;j++){
                a[j-1]=a[j-1]&a[j];
        }
        a[n-i+1]=0;
        for(int j=1;j<=n;j++){

            }

            if(i==m-1){
                sort(a+1,a+n+1,cmp);

            }
    }
    cout<<a[1];}
    else{
        cout<<a[m];
    }



    return 0;
}
