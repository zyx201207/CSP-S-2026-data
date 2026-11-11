#include<iostream>
#include<algorithm>
using namespace std;
long long a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int j=1;j<m;j++){
	for(int i=1;i<=n;i++){
		b[i]=a[i] & a[i-1];
	}
	for(int i=1;i<=n;i++){
		a[i]=b[i];
	}
	}
	long long maxx=-1;
	for(int i=1;i<=n;i++){
		if(maxx<b[i]){
			maxx=b[i];
		}
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
