#include <bits/stdc++.h>
using namespace std;

string s;
int main (){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin >> n;
char a;
long long m,sz=0,sum=0;
for (int i=1;i<=n;i++){
    cin >> m >>a;
    sz+=m;

    for (int i=1;i<=m;i++){
        s=s+a;
    }
}
int i,j;
i=0;
j=sz;
while (i<=j){
    if (s[i]==s[j]){
        i++;
        j--;
    }
    if (s[i]!=s[j]){
        sum+=1;
        i++;
        j--;
    }
}
cout <<sum;
return 0;
}
