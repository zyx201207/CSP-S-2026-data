#include<bits/stdc++.h>
using namespace std;
long long n,m,dd,yy;
long long a[200009];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(m>=3){
                for(int z=1;z<=n;z++){
                    if(m>=4){
                        for(int x=1;x<=n;x++){
                            if(m>=5){
                                for(int c=1;c<=n;c++){
                                    if(m>=6){
                                        for(int v=1;v<=n;v++){

                                                if(i!=j&&j!=z&&i!=z&&i!=x&&j!=x&&z!=x&&c!=i&&c!=j&&c!=z&&c!=x&&i!=v&&j!=v&&z!=v&&x!=v&&c!=v){
                                                yy=a[i]&a[j]&a[z]&a[x]&a[c]&a[v];
                                                dd=max(dd,yy);
                                                }
                                                }

                                            }
                                        else{
                                            if(i!=j&&j!=z&&i!=z&&i!=x&&j!=x&&z!=x&&c!=i&&c!=j&&c!=z&&c!=x){
                                            yy=a[i]&a[j]&a[z]&a[x]&a[c];
                                            dd=max(dd,yy);
                                            }
                                        }
                                }
                                }

                            else{
                                if(i!=j&&j!=z&&i!=z&&i!=x&&j!=x&&z!=x){
                                yy=a[i]&a[j]&a[z]&a[x];
                                dd=max(dd,yy);
                                }
                            }
                        }
                        }
                    else{
                        if(i!=j&&j!=z&&i!=z){
                        yy=a[i]&a[j]&a[z];
                        dd=max(dd,yy);
                        }
                    }

            }
            }
            else{
                if(i!=j){
                yy=a[i]&a[j];
                dd=max(dd,yy);
                }
            }


    }
    }
    cout<<dd;

    return 0;

}

