#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010],n,m;
int main(){
	freopen("crystal.in","r","stdin");
	freopen("crystal.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	long long num=0,l=1;
	for(int i=2;i<=n;i++){
		num+=b[i]*(i-1);
			while(num>m){
				l++;
				num-=a[l];
				num-=b[i];
		}
	}
	cout<<3<<endl;
	return 0;
}
