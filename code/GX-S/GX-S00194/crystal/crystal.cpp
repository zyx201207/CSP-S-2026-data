#include<bits/stdc++.h>
using namespace std;
int p[10000];
int ch[10000];
int main(){
    freopen("crystal1.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n,m;
    for(int i=0;i<=n;i++){
        cin>>p[i];
        //cout<<p[i];
    }
    int r=0;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
                if(j>i){
                int u;
                //cout<<p[i]<<" "<<p[j];
                u=p[i]-p[j];
                if(u<0)u=-u;
                else u=u;
                ch[r]=u;
                r++;

                //cout<<c[r]<<endl;
                }
                /*if(j==i){
                  cha[r]=m+1;
                  r++;
                }*/
        }
    }
    int a=0;
    for(int i=0;i<n*n;i++){
        if(ch[i+1]<ch[i]){
            a=ch[i];
            ch[i]=ch[i+1];
            ch[i+1]=a;
            cout<<ch[i];
        }
    }
   // sort(cha[1],cha[n*n]);
    int ans,co= 0;
    int ou=0;
    for(int j=1;j<=m;j++){

            if(ans<m){
            if(ans+ch[ou]<=m){
            ans+=ch[ou];
            co+=1;
            ou++;

        }
            }
            if(ans==m){
            cout<<co;

            }

        }
cout<<co;
return 0;
    }











