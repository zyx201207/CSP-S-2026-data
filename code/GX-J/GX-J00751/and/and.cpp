#include <bits/stdc++.h>

using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n;
    cin>>n;
    int m[1000000],s=4,k=0,l=0,p=0;
    for(int i=1;i<=n;i++){
        cin>>m[i];
        if(m[i]==1&&k!=0){
                k++;
            s+=1;
        }if(m[i]==2&&l==0){
            l++;
            s+=2;
        }if(m[i]==3&&p==0){
            p++;
            s+=3;
        }
    }
    cout<<s;
    return 0;
}
