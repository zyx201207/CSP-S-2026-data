
#include<bits/stdc++.h>
//Oct31==Dec25?
using namespace std;
int hh(long long i,long long j){
if(i>j){
    return j;
}else return i;


}
int main(){
    freopen("crystal.in","w",stdin);
    freopen("crystal.out","r",stdout);
   int n,m;
   long long a[10005],cnt[555][555]={0},ans[555]={0},app[555][55]={0},aaa[555]={0},ann[555]={0},g=2,pp[100]={0};
   cin>>n>>m;
   for(int i=1;i<=n;i++)
    {
       cin>>a[i];

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cnt[i][j]=a[i]-a[j];


        }

    }

    for(int i=1;i<=n;i++)
    {


        for(int j=1;j<=n;j++)
        {
                g++;

           if(cnt[i][j]>0){
                ans[i]+=cnt[i][j];

                if(ans[i]==m)
                    {
                    cout<<g;
                      break;
                }

                  g=2;

            }



    }
    if(ans[i]>m){
        ans[i-1]=pp[i];
                }

    }
        sort(pp+1,pp+n+1);
         sort(ans,ans+n);
         if(ans[n]<m)
            {
            cout<<g-1;
         }
        if(g==2){
                for(int i=0;i<n;i++){

                    if(pp[i]!=0){
                        cout<<pp[i];
                        break;
                    }




                }

        }





return 0;
}

