#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],k=0,f=0;
bool cmp(int x,int y){
	return x>y;
}
int s(int x,int y){
	if(x==y) return x;
	bool a[1000000],b[1000000],c[1000000];
	int i=1,q=0;
	while(x!=0||y!=0){
		a[i]=x%2;
		b[i]=y%2;
		i++;
		x/=2;
		y/=2;
	}
	for(int j=i;j>=1;j--){
		c[i]=a[i] and b[i];
	}
	int k=1;
	for(int j=1;j<=i;j++){
		q+=c[j]*k;
		k*=2;
	}
	return q;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2&&n==2){
		f=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&s(a[i],a[j])!=0){
					k=1;
					break;
				}
			}
			if(k==1) break;
		}
	}
	if(k==0&&f==1){
		cout<<0;
	}else{
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
	}
	return 0;
}
