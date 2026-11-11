#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
long long L=0;
cin>>n;
vector<int>num(n);
vector<char>cha(n);
vector<char>s(L);
for(int i=0;i<n;i++){
    cin>>num[i];
    cin>>cha[i];
    L+=num[i];
    for(long long j=L-num[i];j<L;j++)
    {
        s[j]=cha[i];
    }

}
int m=0;
for(long long i=0;i<floor(L/2);i++)
{
    if(s[i]!=s[L-i+1])
    {
        m++;
    }
}

cout<<m;

return 0;
}

