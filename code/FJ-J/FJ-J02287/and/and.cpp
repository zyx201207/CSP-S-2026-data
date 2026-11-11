#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[25];
int niam(){
	long long maax=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[i]&a[j])>maax)maax=a[i]&a[j];
		}
	}
	return maax;
}
int nnnn(){
	int sum=a[1];
	for(int i=2;i<=n;i++){
		sum=a[i]&sum;
	}return sum;
}
void mas(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}sort(a+1,a+1+n);
	if(m==1)cout<<a[n];
	else if(n<=2000&&m==2)cout<<niam();
	else if(m==n)cout<<nnnn();
	else cout<<1;
	}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		mas();	
	}
	return 0;	
}
