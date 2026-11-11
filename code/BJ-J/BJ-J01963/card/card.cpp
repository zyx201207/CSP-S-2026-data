#include<bits/stdc++.h>
using namespace std;
int a[500005];
int d[500005];
int b[500005];
int main(){
    int n,m,i,p;
    int s[m];
    for(int c=0;c<m;c++){
        s[c]=0;
    }
    i=0;
    cin>>n,m;
    for(int j=0;j<n;j++){
        cin>>a[j];
    }
    for(int z=0;z<n;z++){
        while(i<n){
            p=i;
            b[i]=a[p];
            for(int l=0;l<i;l++){
                if(b[i]==b[l]){
                    i=l;
                    for(int o=l;o<i;o++){
                        b[o]==0;
                    }
                }
            }
            i+1;
        }
        for(int u=0;u<m;u++){
            for(int q=0;q<m;q++){
                if(b[u]==q) s[q]+=1;
            }
        }
    }
    for(int t=0;t<m;t++){
        cout<<s[t];
    }
}
