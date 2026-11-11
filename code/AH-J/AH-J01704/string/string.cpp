#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
string s;
char a,p;
long long c,h,k[210001],n,q;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k[i]>>p;
        for(int j=1;j<=k[i];j++) s+=p;
    }q=s.size()-1;
    for(;;){
        if(s[q]!=s[h]) c++;
        q++;
        h--;
        if(q>=h) break;
    }
    cout<<c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
比较
    q,h
a,f 1,6
b,e 2,5
c,d 3,4

    +1,-1
    end:q>h
*/
