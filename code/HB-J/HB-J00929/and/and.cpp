#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxx=0;
    cin>>n>>m;
    int s[n+5]={0};
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[i]|s[j]>maxx) maxx=s[i]|s[j];
            }
        }
    }
    if(m==3){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int g=j+1;g<n;g++){
                    if(s[i]|s[j]|s[g]>maxx) maxx=s[i]|s[j]|s[g];
                }
            }
        }
    }
    if(m==4){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int g=j+1;g<n;g++){
                    for(int q=g+1;q<n;q++){
                        if(s[i]|s[j]|s[g]|s[q]>maxx) maxx=s[i]|s[j]|s[g]|s[q];
                    }
                }
            }
        }
    }
    if(m==5){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int g=j+1;g<n;g++){
                    for(int q=g+1;q<n;q++){
                        for(int w=q+1;w<n;w++)
                            if(s[i]|s[j]|s[g]|s[q]|s[w]>maxx) maxx=s[i]|s[j]|s[g]|s[q]|s[w];
                    }
                }
            }
        }
    }
    if(m==6){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int g=j+1;g<n;g++){
                    for(int q=g+1;q<n;q++){
                        for(int w=q+1;w<n;w++){
                            for(int e=w+1;e<n;e++)
                                if(s[i]|s[j]|s[g]|s[q]|s[w]|s[e]>maxx) maxx=s[i]|s[j]|s[g]|s[q]|s[w]|s[e];
                        }
                    }
                }
            }
        }
    }
    cout<<maxx;
    return 0;
}
