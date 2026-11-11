#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool cmp(int a,int b){
	int sum1=0,sum2=0,x=a,y=b;
	while(x!=0){
		if(x%2==1)sum1++;
		x/=2;
	}while(y!=0){
		if(y%2==1)sum2++;
		y/=2;
	}if(sum1==sum2) return a>b;
	else return sum1>sum2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
	}cout<<ans;
	return 0;
}
