#include <bits/stdc++.h>
using namespace std;
long long n,m;
const int k=5e5;
int a[k]={0};
int b[k]={0};
int sum=0;
int t=0;
int w=0;
long long z=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int targe=0;
    for(int z=0;z<n;z++){
        sum=0;
        t=0;
        for(int j=0;j<n;j++){
            b[j]=a[targe]-a[j];
        }

        for(int i=0;i<n;i++){
            if(b[i]>0&&sum+b[i]<=m){
                sum=sum+b[i];
                t++;

            }
            if(b[i]==0){
                t++;
            }
        }
        targe++;
        w=max(w,t);
    }


    cout<<w;




    return 0;
}
