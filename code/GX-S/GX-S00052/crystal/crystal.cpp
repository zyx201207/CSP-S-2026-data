#include<bits/stdc++.h>
using namespace std;
int a,b,p;
int c[500001],e[500001],q[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crysral.ans","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>c[i];
    }
    sort(c+1,c+1+a);
    for (int i=1;i<=a;i++){
        for (int j=1;j<=a;j++){
            e[i]=c[i];
        }
        for (int j=i;j<=a;j++){
            h=b;
            int l=i
            while (h>0){
                if(e[l]<e[l+1]){
                    e[l]=e[l]+1;
                    h=h-1;
                }
                if (e[l]==e[l+1]  && h>=2){
                    e[l]=e[l]+1;
                    e[l+1]=e[l+1]+1;
                    h=h-2;
                }
            }
            for (int n=1;n<=a;n++){
                for (int m=1;m<=a;m++){
                    if(e[m]==n){
                        q[n]+=1;
                    }
                }
            }
            sort(q+1,q+1+a*2);
            if (p<q[a*2]){
                p=q[a*2];
            }
        }
    }
    cout<<p;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
