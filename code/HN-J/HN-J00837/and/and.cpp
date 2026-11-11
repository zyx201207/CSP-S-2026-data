#include <bits/stdc++.h>
using namespace std;
int a[200004],b[5000000];
int cmp(int a,int b){
	return a>b;
}
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(m==1){
		for(int i=1;i<=n;i++){
			sort(a+1,a+n+1,cmp);
			x=a[i];
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				b[i]=a[i]&a[j];
//				cout<<b[i]; 
				sort(b+1,b+n+1,cmp);
				x=b[1];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			b[i]=a[i]&a[j];
//			cout<<b[i]; 
			sort(b+1,b+n+1,cmp);
			x=b[1];
		}
	}
	cout<<x;
	return 0;
} 
