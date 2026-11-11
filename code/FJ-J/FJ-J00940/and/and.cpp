#include<iostream>
#include<cstdio>
using namespace std;
int a[1000005]; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,ans=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		if(ans<p) ans=p;
		a[p]++;
	}
	a[ans]--;
	m--;
	for(int i=1000005;i>=0;i--){
		while(a[i]!=0&&m!=0){
			ans=ans&i;
			a[i]--;
			m--;
		}
	}
	cout<<ans;
	return 0;
}
