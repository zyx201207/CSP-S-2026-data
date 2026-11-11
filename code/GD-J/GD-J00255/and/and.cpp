#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
bool man(int x){
	long long sum=1;
	for(int i=1;i<=31;i++){
		sum*=2;
		if(sum==x)return 1;
	}
	return 0;
}
int manba(int x){
	int sum=0;
	while(x!=0){
		int ls=x%2;
		if(ls==1){
			sum++;
		}
		x/=2;
	}
	return sum;
}
struct node{
	int z,s;
}b[200005];
bool cmp1(node x,node y){
	return x.s>y.s;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i].z=a[i];
		b[i].s=manba(a[i]);
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp1);
	int sum1=a[1];
	for(int i=2;i<=m;i++){
		sum1=sum1&a[i];
	}
	int sum3=b[1].z;
	for(int i=2;i<=m;i++){
		sum3=sum3&b[i].z;
	}
	int sum2=0;
	for(int i=1;i<=m;i++){
		if(man(a[i])==1){
			m++;
			if(m>n){
				sum2=0;
				break;
			}
			continue;
		}else{
			if(sum2==0)sum2=a[i];
			else sum2=sum2&a[i];
		}
	}
	cout<<max(sum2,max(sum1,sum3));
	return 0;
} 
