#include<bits/stdc++.h>
using namespace std;
int a[300005],b[500005],c[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
        c[i]=b[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j;k<=n;k++){
                if(b[k]==b[j]){
                    for(int o=j;o<k;o++){
                        b[o]=0;
                    }
                }
            }
        }
        for(int q=1;q<=n;q++){
            if(b[q]!=0){
                a[b[q]]++;
            }
        }
        for(int k=1;k<=n;k++){
            b[i]=c[i];
        }
    }
    for(int i=1;i<=m;i++){
        if(i==m){
            cout<<a[m]+1;
        }else{
            cout<<a[i]<<" ";
        }
    }
	return 0;
}
