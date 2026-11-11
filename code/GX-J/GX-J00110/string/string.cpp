#include<bits/stdc++.h>
using namespace std;

int main()
{
freopen{"string.in"."r",stdin};
freopen{"string.out","w",stdout};
string s,NEW,cnt=0;
int n,m;
cin >> n >> m;
for(int i=0;i<0;i++){
    cin >> s[i];
}
for(int j=s-1;j>=0;j--){
    NEW +=s[j];
}
for(int k=0;k<s;++k){
    if(s[k]=NEW[k]){
        ++cnt;
    }
}
    return 0;
}

