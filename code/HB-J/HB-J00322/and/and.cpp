#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a[200005];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	}
	if(m==1){
		long long v;
		for(int i=2;i<=n;i++){
			v=max(a[i],a[i-1]);
		}
		cout<<v;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-1-m];


	return 0;
}
