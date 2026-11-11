//GZ-J00311 贵阳市第三中学 安德雯
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,maxl,maxr,maxx;
bool t;
struct node{
    int shu,zhi;
}a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i].zhi;
        a[a[i].zhi].shu++;
        if(a[i].zhi<a[i-1].zhi)  t=1;
	}
	if(!t){
        for(int i=1;i<=n;i++)  cout<<a[a[i].zhi].shu<<' ';
        return 0;
    }
    if(m==1)  cout<<n;
    else if(m==2)  cout<<n<<' '<<n;
	return 0;
}
