#include<iostream>
#include<algorithm>
using namespace std;
int a[1000001],max1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(max1<a[i]&a[j]&&i!=j){
					max1=a[i]&a[j];
				}
			}
		}
		cout<<max1;
	}else{
		max1=a[1];
		for(int i=2;i<=n;i++){
			max1&=a[i];
		}
		cout<<max1;
	}
	return 0;
} 
