#include<bits/stdc++.h>
using namespace std;
long long z,m,a[500000+10],mx=-1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>z>>m;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	sort(a+1,a+z+1,cmp);
	int x=a[1]-a[2];
	bool A=1;
	for(int i=2;i<=z-1;i++){
		if(a[i]-a[i+1]!=x){
			A=0;
			break;
		}
	}
	if(A){
		int sum=0;
		for(int i=1;i<=z;i++){
			if(m>=a[1]-a[i]){
				m-=(a[1]-a[i]);
				sum++;
			}else{
				break;
			}
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=z;i++){
		long long c=m,sum=0;
		for(int j=i;j<=z;j++){
			if(c>=a[i]-a[j]){
				sum++;
				c-=(a[i]-a[j]);
			}else{
				break;
			}
		}
		mx=max(mx,sum);
	}
	cout<<mx;
	return 0;
}
