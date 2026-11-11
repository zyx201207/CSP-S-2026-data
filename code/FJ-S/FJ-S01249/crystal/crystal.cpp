#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ma=-1;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		a[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
		int x=1,sum=0;
		for(int j=i;j<=n;j++){
			if(m-sum>=a[j]*x){
				sum+=a[j]*x;
				x++;
			}else if(m-sum>=a[j]*(x-1)){
				sum+=a[j]*x;
			}else{
				break;
			}
		}
		ma=max(x,ma);
	}
	cout<<ma;
} 
