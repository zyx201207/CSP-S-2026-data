#include<bits/stdc++.h>
using namespace std;
int n;
long long l,r,d,a,w,h;
bool j;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    w=1;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        d+=a;
        for(int j=1;j<=a;j++){
            s[w]=c;
            w++;
        }
    }
    if(d%2==0) j=false;
    else j=true;
    d=d/2;
    if(j){
        l=d;
        r=d+2;
    }else{
        l=d;
        r=d+1;
    }
    h=0;
    while(l>=0 && r<=w-1){
        if(s[l]!=s[r]){
            h++;
        }
        l--;
        r++;
    }
    cout<<h;
    fclose(stdin);
    fclose(stdout);
    return 0;
}