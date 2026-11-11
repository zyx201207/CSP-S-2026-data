#include<bits/stdc++.h> 
using namespace std;
long long q[1000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long num=0;
	for(long long i=1;i<=n;i++){
		cin>>q[i];
		
	}
	sort(q+1,q+1+n,cmp);
	num=q[1];
	for(long long i=2;i<=m;i++){
		num=num&q[i];
	}
	cout<<num;
	return 0;
}
