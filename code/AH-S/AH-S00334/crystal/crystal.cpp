#include<bits/stdc++.h>
using namespace std;
long long a[100100],mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long  n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2){
		mid=a[n/2+1];
	}
	else{
		mid=a[n/2];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		if(m<abs(a[i]-mid)){
			cout<<t;
			return 0;
		}else{
			m-=abs(a[i]-mid);
			++t;
		}
	}cout<<t;
	return 0;
}
