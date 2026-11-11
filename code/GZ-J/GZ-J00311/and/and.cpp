//GZ-J00311 贵阳市第三中学 安德雯
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
struct node{
	int shu;
    long long er;
}a[N];
long long zhuan(int a){
    int temp=1,cnt=0;
	long long ans=0;
    while(a>temp)  temp=temp<<1;
    for(int i=temp;i>=1;i=i>>1){
        ans*=10;
        if(a>=temp)  ans+1;
    }
    return ans;
}
bool cmp(node a,node b){
    if(a.er!=b.er)  return a.er>b.er;
    return a.shu>b.shu;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i].shu;
        a[i].er=zhuan(a[i].shu);
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[m].shu;
	return 0;
}
