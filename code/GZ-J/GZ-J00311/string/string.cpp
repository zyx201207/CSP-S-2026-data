//GZ-J00311 贵阳市第三中学 安德雯
#include<bits/stdc++.h>
const int N=2e5+5;
int n,shu[N],ans,icnt,jcnt;
char a[N];
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>shu[i]>>a[i];
	icnt=shu[1],jcnt=shu[n];
	for(int i=1,j=n;i<j;){
        if(a[i]!=a[j])  ans+=min(icnt,jcnt);
        if(icnt>=jcnt)  icnt-=jcnt,jcnt=0;
        else  jcnt-=icnt,icnt=0;
        if(icnt==0){
            i++;
            icnt=shu[i]
        }
        if(jcnt==0){
            j--;
            jcnt=shu[j];
        }
	}
	cout<<ans;
	return 0;
}
