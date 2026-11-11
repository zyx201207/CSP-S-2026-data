#include <bits/stdc++.h>
using namespace std;
int a[100100],b[100100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	sort(b+1,b+1+n);
	for(int i=2;i<=n;i++){
		b[i]=b[i]+b[i-1];
	}
	int num=1;
	for(int i=n;i>=2;i--){
		if(m-b[i]>=0){
			m-=b[i];
			num+=1;
		}
	}
	cout<<num;
	return 0;
}
