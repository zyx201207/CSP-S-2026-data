#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200010],maxa=0,sum=0;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxa) maxa=a[i];
	}
	if(n==m){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		maxa=sum;
	}
	else if(m==2){
		maxa=0;
		for(int i=1;i<=n-1;i++){
			for(int j=2;j<=n;j++){
				sum=a[i]&a[j];
				if(sum>maxa) maxa=sum;
			}
		}
	}
	cout<<maxa;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
