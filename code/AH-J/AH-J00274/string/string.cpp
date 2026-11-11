#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a,L=0,l,r;
string s,c;
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
        L+=a;
    }
    if(L%2==0){
        l=L/2;
        r=L/2+1;
        while(l!=0){
            if(s[l-1]!=s[r-1]){
                cnt++;
            }
            l--;
            r++;
        }
    }else{
        l=r=L/2+1;
        while(l!=0){
            if(s[l-1]!=s[r-1]){
                cnt++;
            }
            l--;
            r++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

