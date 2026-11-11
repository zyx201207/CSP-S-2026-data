#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,m,t;
int l[2000001],y[2000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ciin>>c>>d;
    for (ini s=1;s<=d;s++){
        cin>>a>>b;
        for (int i=1;i<=a;i++){
            cin>>l[i];
        }
        for (int i=1;i<=a-1;i++){
            for (int j=i+1;j<=a;j++){
                if (l[j]-l[i]<=b){
                    y[j]=l[j]-l[i];
                    e=y[j];
                }
            }
            if(m==e){
                t+=1;
                m=0;
            }
            for (int j=1;j<=2000001;j++){
                y[j]=0;
            }
        }
        if (s==1){
            cout<<t;
        }
        else {
            cout<<endl;
            cout<<t;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
