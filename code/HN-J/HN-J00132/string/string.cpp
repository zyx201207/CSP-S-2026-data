#include<bits/stdc++.h>
using namespace std;
string s=" ";
long long n,ans;
struct node{
	long long geshu;
	char zifu;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].geshu>>a[i].zifu;
	}
	for(int i=1,j=n;i<=j;i+=0)
	{
		long long d=min(a[i].geshu,a[j].geshu);
		if(a[i].zifu==a[j].zifu)
		{
			a[i].geshu-=d;
			a[j].geshu-=d;
		}
		else{
			ans+=d;
			a[i].geshu-=d;
			a[j].geshu-=d;
		}
		if(a[i].geshu<=0)
		{
			i++;
		}
		if(a[j].geshu<=0){
			j--;
		}
	}
	cout<<ans;
	return 0;
}
