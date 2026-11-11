#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a[100001];
    int b[100001]={0};
    int c[100001]={0};
    int n,m,r=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        b[a[i]]++;
        if(b[a[i]]==2){
            b[a[i]]--;
            for(int j=0;j<i;j++){
                if(a[j]==a[i]){
                    int x=j+1;
                    while(x<=i){
                        a[x]=0;
                        x++;
                    }
                }
            }
        }
        for(int j=0;j<m;j++){
            c[a[j]]++;
        }
    }
    for(int i=0;i<m;i++){
       cout<<c[a[i]]<<" ";
    }
    return 0;
}
