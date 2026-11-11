#include<bits/stdc++.h>
using namespace std;

int a[200005],b[35]={0,1},n,m,f[200005],bbb=0;
int da=0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=2;i<=30;i++){
		b[i]=2*b[i-1];
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	bool flag=0;
	int i=31;
	while((i--)>1){
		int* it=upper_bound(a+1,a+1+n,b[i]);
		int iti=upper_bound(a+1,a+1+n,b[i])-a;
		if(it==a+1+n&&*it!=b[i])continue;
		if(n-iti+1<m){
			for(int j=n;j>=iti;j--){
				a[j]-=b[i];
			}
			sort(a+1,a+1+n);
		}
		else{
			for(int j=n;j>=n-m+1;j--){
				f[++bbb]=a[j];
			}
			flag=1;
			break;
		}
	}
	if(flag){
		da=f[1];
		for(int i=2;i<=bbb;i++){
			da&=f[i];
		}
		cout<<da;
	}
}
