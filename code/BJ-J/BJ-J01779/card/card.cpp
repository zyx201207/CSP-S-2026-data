#include<bits/stdc++.h>
using namespace std;
int n,a[5005],s[5005],b[5005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        s[a[i]]++;
        for(int j=1;j<=n;j++)b[j]=a[j];
        for(int j=i+1;j<=n;j++){
            for(int k=i;k<j;k++){
                if(b[k]==b[j]){
                    for(int l=k;l<j;l++)s[b[l]]--,b[l]=0;
                    break;
                }
            }
            s[b[j]]++;
            //for(int k=1;k<=m;k++)cout<<s[k]<<' ';
            //cout<<endl;
        }
    }
    for(int i=1;i<=m;i++)cout<<s[i]<<' ';
return 0;
}
