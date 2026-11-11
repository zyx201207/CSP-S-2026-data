#include<bits/stdc++.h>
using namespace std;
struct sss{
    int a;
    char c;
};
int main(){
    freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
cin>>n;
sss num[250000];
int cnt=0;
for(int i=1;i<=n;i++)
{

    cin>>num[i].a>>num[i].c;
    cnt+=num[i].a;
}
int half=cnt/2;
int another=half+1,k,cnt2=0,l;
if(cnt%2==1)another++;
string s1,s2;
int j=1;
while(j<=half)
{
    cnt2++;
    k=num[cnt2].a;
    for(l=1;l<=k;l++)
    {

        s1[j]=num[cnt2].c;
        j++;
        if(j>half)break;
    }

}
j=another;
if(another==half+2)l+=1;
if(l==k)l=1;
while(j<=cnt)
{

    k=num[cnt2].a;
    while(l<=k)
    {

        s2[j-another+1]=num[cnt2].c;
        j++;
        l++;
    }
    cnt2++;
    l=1;
}
int cnt3=0;
for(int i=1;i<=half;i++)
{

    if(s1[i]!=s2[i])cnt3++;
}
cout<<cnt3;


return 0;
}
