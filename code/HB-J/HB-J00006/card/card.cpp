#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005]={0},top=0,he=1,f=0,flag=0,t=0;
    cin>>n>>m;
    cin>>a[top];
    top++;
    for(int i=1;i<=n;i++){
        cin>>a[top];

        for(int j=0;j<=n;j++){

            if(a[top]==a[j]){

                a[j]=0;
                t=a[top];
                a[top]=0;
                top=j;
                f=1;
                flag=1;

            }
            if(f==1){
                he=he-a[j];
                a[j]=t;
            }

        }
        f=0;
        he=he+a[top];

        cout<<he<<" ";

        flag=0;

        top++;
    }

    return 0;
}
