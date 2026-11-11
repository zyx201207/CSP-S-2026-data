#include<bits/stdc++.h>
using namespace std;
long long n,a,m,l=1,s,sum=0;
char b;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1;i<=n;i++){
           cin>>a>>b;
            m+=a;
            for(register int j=l;j<=m;j++)c[j]=b;
            l=m+1;
	}
	l=m/2;
    s=m;
    for(register int i=1;i<=l;i++){
        if(c[i]!=c[s])sum++;
        s--;
    }
    printf("%d",sum);
	return 0;
}
