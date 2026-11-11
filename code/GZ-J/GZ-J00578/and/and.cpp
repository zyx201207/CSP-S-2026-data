//马辰一帆 GZ-J00578 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
long long n,m,a[200005];
long long sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(int i=2;i<=m;i++){
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
//hymmyyds 
