#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int a,b,s=0,dg=0,m[10001]={0},n[5001]={0},p[10001]={0};
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>m[i];
    }
    for(int i=1;i<=a;i++){
        for(int j=i;j<=a;j++){
            for(int k=1;k<=s;k++){
                if(m[j]==p[k]){
                    dg=k;
                    for(int l=k;l<=s;l++){
                        p[l]=0;
                    }
                    s=dg;
                }
            }
            p[s+1]=m[j];
            s++;
        }
        for(int j=1;j<=s;j++){
            n[p[j]]++;
        }
        dg=0;
        s=0;
    }
    for(int i=1;i<=b;i++){
        cout<<n[i]<<" ";
    }
    return 0;
}
