//GZ-J00589 遵义市第四初级中学 蒋子涵
#include<bits/stdc++.h>
using namespace std;
bool f1=1;
int m,n,a[200005]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bool f=0;
		for(int j=0;j<=30;j++){
			if(pow(2,j)-1==a[i]) f=1;
		}
		if(f==0) f1=0;
	}
	if(f1==0){
		int d=n;
		sum=a[n];
		for(int i=1;i<=m;i++){
			sum=sum and a[d];
			d--;
		}
		cout<<sum;
		return 0;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n+1-m];
		return 0;
	}
	return 0;
}
