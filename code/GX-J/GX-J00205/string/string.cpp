#include<bits/stdc++.h>
using namespace std;
int main()
{freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,m,t=1,ans=0;
string a;
char b;
cin>>n;
for(int i=1;i<=n;i++)
{cin>>m>>b;
while(m>0)
{a[t]=b;
t++;
m--;
}


}
for(int i=1;i<=t-1;i++)
{if(a[i]!=a[t-i])
{a[i]=a[t-i];
ans++;

}

}
cout<<ans;
return 0;
}
