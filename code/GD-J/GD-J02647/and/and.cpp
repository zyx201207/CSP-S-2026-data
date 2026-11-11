#include<iostream>
using namespace std;
int n,m,a[200001],c=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)c=max(c,a[i]);
		cout<<c;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[i]&a[j])>c)c=(a[i]&a[j]);
			}
		}
		cout<<c;
	}
	else if(m==n){
		c=a[1];
		for(int i=1;i<=n;i++)c=(c&a[i]);
		cout<<c;
	}
	else {
		for(int i=1;i<=n;i++)c=max(c,a[i]);
		for(int i=1;i<=m;i++){
			int b=c-2*c;
			for(int j=1;j<=n;j++){
				int aa=(c&a[j]);
				if(aa>=b&&a[j]!=-1){
					b=aa;
					a[j]=-1;
				}
			}
			c=b;
		}
		cout<<c;
	}
}
