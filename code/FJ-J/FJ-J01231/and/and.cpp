#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n,cmp);
	//sum=a[1];
	//for(int i=2;i<=m;i++){
		//sum=int(sum&a[i]);
	//}
	//cout<<sum<<endl;
	cout<<a[m];
	return 0;
}

