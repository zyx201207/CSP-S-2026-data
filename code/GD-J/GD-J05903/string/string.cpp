#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
long long n,ans;
struct aa{
	char x;
	int s;
}a[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].x;
	}
	for(int i=1,j=n;i<j;)
	{
		int k=0;
		if(a[i].x!=a[j].x)
			k=1;
		if(a[i].s>a[j].s)ans+=k*(a[i].s-a[j].s),a[i].s-=a[j--].s;
		else if(a[i].s<a[j].s)ans+=k*(a[j].s-a[i].s),a[j].s-=a[i++].s;
		else ans+=k*(a[i].s),i++,j--;
	}
	cout<<ans;
	return 0;
} 

