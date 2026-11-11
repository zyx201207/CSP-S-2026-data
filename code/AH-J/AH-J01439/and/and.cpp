#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[2000010],max1,max2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	const int n1=n,m1=m;
	for(int i=1;i<=n1;i++){
		cin>>a[i];
	}
	if(m1==2){
		sort(a+1,a+n1+1);
		cout<<a[n1-1];
	}else if(m1==1){
		sort(a+1,a+n1+1);
		cout<<a[n1];
	}else{
		sort(a+1,a+n1+1);
		cout<<a[n1-m1+1];
	}
	return 0;
}
