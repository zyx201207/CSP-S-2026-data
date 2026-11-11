#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxx=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int ji=0;
	maxx=a[n];
	while(ji<m){
		maxx=(maxx&a[n-ji]);
		ji++;
	}
	cout<<maxx;
	return 0;
}
