#include<bits/stdc++.h>
using namespace std;
#define int long long
int two_ten(int n){
	int s=0,i=0;
	while(n!=0){
		s+=(n%10)*pow(2,i);
		n/=10;
		i++;
	}
	return s;
}
int ten_two(int n){
	int s=0,i=0;
	while(n!=0){
		s+=(n%2)*pow(10,i);
		n/=2;
		i++;
	}
	return s;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100010]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int s=ten_two(a[1]);
		for(int i=2;i<=n;i++){
			int e=ten_two(a[i]);
			s=s&e;
		}
		cout<<two_ten(s);
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]=ten_two(a[i]);
	}
	int MAX=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				MAX=max(MAX,a[i]&a[j]);
			}
		}
		cout<<two_ten(MAX);
		return 0;
	}
	//cout<<two_ten(ten_two(a[n-1])&ten_two(a[n-2]));
	cout<<0;
	return 0;
}
