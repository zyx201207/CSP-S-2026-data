#include<bits/stdc++.h>
using namespace std;
int num(int a){
	int sum=0;
	while(a>0){
		int x=a%2;
		if(x==1){
			sum++;
		} 
		a=a/2;
	}
	return sum;
}
struct a1{
	int e;
	int y;
}b[10010];
int cmp(a1 x,a1 y){
	return x.e>y.e;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	int n,m;
	cin>>n>>m;
	int i;
	int ans;
	for(i=0;i<n;i++){
		cin>>b[i].y;
		b[i].e=num(b[i].y);
		sort(b,b+i,cmp);
		ans=b[0].y;
		for(int j=1;j<m;j++){
			ans=ans&b[i].y;
		}
	} 
	cout<<ans;
	return 0;
} 
