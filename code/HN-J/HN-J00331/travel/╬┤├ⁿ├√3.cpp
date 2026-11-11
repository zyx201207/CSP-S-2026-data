#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],tmp[200005];
void lisanhua(){
	int now=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])tmp[++now]=a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(tmp+1,tmp+now+1,a[i])-tmp;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	lisanhua();
	for(int i=1;i<=n;i++){
		cout<<tmp[a[i]];
	}
}
