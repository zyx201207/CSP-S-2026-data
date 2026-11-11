#include<bits/stdc++.h>
using namespace std;
string a="",b,c1;
int n,c;
long long sum=0;
void f(){
	for(int i=0;i<c;i++){
		a=a+c1;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c>>c1;
		f();
	}
	for(long long i=a.size()-1;i>=0;i--){
		b+=a[i];
	}
	long long i=0;
	while(a!=b && i<=a.size()/2){
		if(b[i]!=a[i]){
			b[i]=a[i];
			sum++;
		}
		i++;
	}
	cout<<sum;
	return 0;
}
