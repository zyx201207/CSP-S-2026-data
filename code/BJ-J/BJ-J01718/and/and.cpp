#include<bits/stdc++.h>
using namespace std;
int a[200001];
bool cmp(int a,int b){
    return a>b;
}
int y(int a,int b){
    return a&b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    int maxs=0;
    if(m==2){
        for(int i=1;i<=n-1;i++){
            int s1=a[i];
            for(int j=i+1;j<=n;j++){
                int s2=a[j];
                int sh=s1&s2;
                if(sh>maxs) maxs=sh;
            }
        }
    }else if(m==3){
        for(int i=1;i<=n-2;i++){
            int s1=a[i];
            for(int j=i+1;j<=n-1;j++){
                int s2=a[j];
                for(int k=j+1;k<=n;k++){
                    int s3=a[k];
                    int sh=s1&s2&s3;
                    if(sh>maxs) maxs=sh;
                }
            }
        }
    }else if(m==4){
        for(int i=1;i<=n-3;i++){
            int s1=a[i];
            for(int j=i+1;j<=n-2;j++){
                int s2=a[j];
                for(int k=j+1;k<=n-1;k++){
                    int s3=a[k];
                    for(int t=k+1;t<=n;t++){
                        int s4=a[t];
                        int sh=s1&s2&s3&s4;
                        if(sh>maxs) maxs=sh;
                    }
                }
            }
        }
    }else if(m==5){
        for(int i=1;i<=n-4;i++){
            int s1=a[i];
            for(int j=i+1;j<=n-3;j++){
                int s2=a[j];
                for(int k=j+1;k<=n-2;k++){
                    int s3=a[k];
                    for(int t=k+1;t<=n-1;t++){
                        int s4=a[t];
                        for(int g=t+1;g<=n;g++){
                            int s5=a[g];
                            int sh=s1&s2&s3&s4&s5;
                            if(sh>maxs) maxs=sh;
                        }
                    }
                }
            }
        }
    }else if(m==6){
        for(int i=1;i<=n-5;i++){
            int s1=a[i];
            for(int j=i+1;j<=n-4;j++){
                int s2=a[j];
                for(int k=j+1;k<=n-3;k++){
                    int s3=a[k];
                    for(int t=k+1;t<=n-2;t++){
                        int s4=a[t];
                        for(int g=t+1;g<=n-1;g++){
                            int s5=a[g];
                            for(int u=g+1;g<=n;u++){
                                int s6=a[u];
                                int sh=s1&s2&s3&s4&s5&s6;
                                if(sh>maxs) maxs=sh;
                            }
                        }
                    }
                }
            }
        }
    }else if(m==7){
        for(int i=1;i<=n-6;i++){
            int s1=a[i];
            for(int j=i+1;j<=n-5;j++){
                int s2=a[j];
                for(int k=j+1;k<=n-4;k++){
                    int s3=a[k];
                    for(int t=k+1;t<=n-3;t++){
                        int s4=a[t];
                        for(int g=t+1;g<=n-2;g++){
                            int s5=a[g];
                            for(int u=g+1;g<=n-1;u++){
                                int s6=a[u];
                                for(int w=u+1;w<=n;w++){
                                    int s7=a[w];
                                    int sh=s1&s2&s3&s4&s5&s6&s7;
                                    if(sh>maxs) maxs=sh;
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(m==8){
        for(int i=1;i<=n-7;i++){
            int s1=a[i];
            for(int j=i+1;j<=n-6;j++){
                int s2=a[j];
                for(int k=j+1;k<=n-5;k++){
                    int s3=a[k];
                    for(int t=k+1;t<=n-4;t++){
                        int s4=a[t];
                        for(int g=t+1;g<=n-3;g++){
                            int s5=a[g];
                            for(int u=g+1;g<=n-2;u++){
                                int s6=a[u];
                                for(int w=u+1;w<=n-1;w++){
                                    int s7=a[w];
                                    for(int p=w+1;p<=n;p++){
                                        int s8=a[p];
                                        int sh=s1&s2&s3&s4&s5&s6&s7&s8;
                                        if(sh>maxs) maxs=sh;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(m==9){
        for(int i=1;i<=n-8;i++){
            int s1=a[i];
            for(int j=i+1;j<=n-7;j++){
                int s2=a[j];
                for(int k=j+1;k<=n-6;k++){
                    int s3=a[k];
                    for(int t=k+1;t<=n-5;t++){
                        int s4=a[t];
                        for(int g=t+1;g<=n-4;g++){
                            int s5=a[g];
                            for(int u=g+1;g<=n-3;u++){
                                int s6=a[u];
                                for(int w=u+1;w<=n-2;w++){
                                    int s7=a[w];
                                    for(int p=w+1;p<=n-1;p++){
                                        int s8=a[p];
                                        for(int r=p+1;r<=n;r++){
                                            int s9=a[r];
                                            int sh=s1&s2&s3&s4&s5&s6&s7&s8&s9;
                                            if(sh>maxs) maxs=sh;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }else if(m==10){
        for(int i=1;i<=n-9;i++){
            int s1=a[i];
            for(int j=i+1;j<=n-8;j++){
                int s2=a[j];
                for(int k=j+1;k<=n-7;k++){
                    int s3=a[k];
                    for(int t=k+1;t<=n-6;t++){
                        int s4=a[t];
                        for(int g=t+1;g<=n-5;g++){
                            int s5=a[g];
                            for(int u=g+1;g<=n-4;u++){
                                int s6=a[u];
                                for(int w=u+1;w<=n-3;w++){
                                    int s7=a[w];
                                    for(int p=w+1;p<=n-2;p++){
                                        int s8=a[p];
                                        for(int r=p+1;r<=n-1;r++){
                                            int s9=a[r];
                                            for(int z=r+1;z<=n;z++){
                                                int s10=a[z];
                                                int sh=s1&s2&s3&s4&s5&s6&s7&s8&s9&&s10;
                                                if(sh>maxs) maxs=sh;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<maxs;
    return 0;
}
