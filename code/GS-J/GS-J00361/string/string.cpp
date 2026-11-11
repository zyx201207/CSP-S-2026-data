#include <bits/stdc++.h>
using namespace std;
string x[100000000],b[100000000];
long long c=0,n,y=0,a[20000000000],sum=0;
bool f=true;
void v(int a,string b){
	for(long long j=0;j<a;j++){
			x[c]=b;
			c++;
		}
}
void s(){
	for(long long i=0;i<y;i++){
		if(x[i]!=x[y-i-1]){
			f=false;
			x[y-i-1]=x[i];
			sum++;
		}
	}
}
void cn(){
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		v(a[i],b[i]);
		y+=a[i];
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cn();
	s();
	if(f){
		cout<<0;
		return 0;
	}
	cout<<sum;
	return 0;
}
