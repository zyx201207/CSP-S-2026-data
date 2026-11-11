#include<bits/stdc++.h>
using namespace std;
int a[200010];
int zhuan(int x){
int s=x;
	long long ans=1;
	long long sum=0;
	long long a[200010];
	while(x>1){
		x=x/2;
		ans++;
}
    x=s;
    for(int i=ans;i>0;i--){
    	a[i]=x%2;
    	x=x/2;
	}
	for(int i=1;i<=ans;i++){
		sum=a[i]*pow(10,ans-i)+sum;
	}
	return sum;
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	long long max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
}
    for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ans=a[i]&a[j];
			if(ans>max){
				max=ans;
			}
		}
	}
	cout<<max;
	return 0;
}
