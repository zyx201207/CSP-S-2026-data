#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char s;
    long long n,a[2][200005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[0][i]>>s;
        a[1][i]=s-'a';
    }
    int i=1,j=n;
    long long cnt=0;
    int m;
    while(i<j){
        if(a[1][i]!=a[1][j]){
            if(a[0][i]<a[0][j]){
                cnt+=a[0][i];
                a[0][j]-=a[0][i];
                i++;
            }else if(a[0][j]<a[0][i]){
                cnt+=a[0][j];
                a[0][i]-=a[0][j];
                j--;
            }else{
                cnt+=a[0][i];
                i++;
                j--;
            }
        }else{
            if(a[0][i]<a[0][j]){
                a[0][j]-=a[0][i];
                i++;
            }else if(a[0][j]<a[0][i]){
                a[0][i]-=a[0][j];
                j--;



            }else{
                i++;
                j--;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
