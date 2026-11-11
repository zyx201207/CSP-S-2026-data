#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[200005];

int tryto(int n,int d){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                for(int l=i+1;l<j;l++){
                    for(int k=j+1;k<j;k++){
                        if(l!=k){
                            if(a[j]-a[l]<=d && a[l]-a[i]<=d &&a[j]-a[k]<=d &&a[k]-a[i]<=d){
                                ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++){
        int n,d;
        scanf("%d%d",&a,&d);
        if(c==11||c==12){
            int t=a[4]-a[3];
            if(2*t<=d){
                cout<<n-2<<endl;
                continue;
            }
        }
        for(int j=1;j<=n;j++){
            //scanf("%d",a[i]);
            cin>>a[i];
            printf("%d\n",tryto(n,d));
            memset(a,0,sizeof(a));
        }
    }



    fclose(stdin);
    fclose(stdout);
    return 0;
}
