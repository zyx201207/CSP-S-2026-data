#include<bits/stdc++.h>
using namespace std;
bool flag[500005]={0};
int a[500005],box[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int box1[500005]={0};
        for(int j=i;j<=n;j++){
            if(box1[a[j]]>=1){
                int box1[500005]={0};
            }
            box1[a[j]]++;
        }
        for(int j=1;j<=m;j++){
            box[j]+=box1[j];
        }
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d ",box[i]);
    }
    return 0;
}
