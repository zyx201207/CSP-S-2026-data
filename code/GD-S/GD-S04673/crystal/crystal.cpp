#include<bits/stdc++.h>
using namespace std;
long long a[600001],c[600000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m;
	long long n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	int sum=0,l=2;
	while(m>0){
		while(c[l]==0&&l<n){
			l++;
		}
		c[l]--;
		m-=l-1;
	}
	for(int i=l;i<=n;i++){
		if(c[i]!=0){
			break;
		}else{
			sum++;
		}
	}
	cout<<sum+l-1<<endl;
	return 0;
} 
