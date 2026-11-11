#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[500001]={};
    int sum[300000]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }for(int i=0;i<n;i++){
        int s[500000]={};
        int s1=0;
        for(int j=i;j<n;j++){
                int f=0;
            for(int k=0;k<s1;k++){
                    if(s[k]==a[j]){
                        s1=k;
                        break;
                    }
            }
                s[s1]=a[j];
                s1++;
        }for(int i=0;i<s1;i++){
            sum[s[i]]++;
        }
    }for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
