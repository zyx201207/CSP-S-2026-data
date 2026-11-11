//GZ-J00660 兴义市弘毅中学 陈润泽 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	int a[n+5]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	} 
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=1;j<n;j++)
				sum=max(a[i]&a[j],sum);
		}
		cout<<sum;
		return 0;
	}
	if(m==n){
		cout<<"1";
		return 0;
	}
	return 0;
}
