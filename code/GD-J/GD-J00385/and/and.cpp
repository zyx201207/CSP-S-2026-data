#include<bits/stdc++.h>
using namespace std;
int n,m;
long long maxn=0;
long long a[200050];

bool cmp(long long c,long long d){
	return c>d;
}

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long v=a[1];
	for(int i=1;i<m;i++)
	{
		v=v&a[i+1];
	}
	cout << v;
	
	return 0;
} 
