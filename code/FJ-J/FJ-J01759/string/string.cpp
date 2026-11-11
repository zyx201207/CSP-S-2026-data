#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;

char con[M];
long long fu[M];
long long pf[M];
int ai;
char ci;
int len,mid,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ai;
		cin>>ci;
		pf[i]=pf[i-1]+ai;
		fu[i]=pf[i-1]+1;
		con[i]=ci;
		len+=ai;
	}
	mid=len/2;
	for(int i=1;i<=mid;i++)
	{
		int pn=len+1-i;
		int pi=upper_bound(fu+1,fu+n+1,pn)-fu-1;
		int ii=upper_bound(fu+1,fu+n+1,i)-fu-1;
		if(con[pi]!=con[ii])ans++;
	}
	cout<<ans;
	
} 
