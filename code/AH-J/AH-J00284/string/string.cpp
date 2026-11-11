#include<iostream>
#include<cstdio>
using namespace std;
int n,a[200005],cnt,l,r;
char c[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s=s+c[i];
        }
    }
    if(s.size()%2==1){
        l=(s.size()+1)/2-1;
        r=(s.size()+1)/2+1;
        s=" "+s;
        while(l>=1){
            if(s[l]!=s[r]) cnt++;
            l--;
            r++;
        }
    }else{
        l=s.size()/2;
        r=s.size()/2+1;
        s=" "+s;
        while(l>=1){
            if(s[l]!=s[r]) cnt++;
            l--;
            r++;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}/*
3
2 a
2 b
1 c
*/
