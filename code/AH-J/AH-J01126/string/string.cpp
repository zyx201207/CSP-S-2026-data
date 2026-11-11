#include<bits/stdc++.h>
using namespace std;
struct hw{
	long long a;
	char b;
}a[10000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
	long long x=n;
	long long sum=0;
	for(int i=1;i<=n/2;i++){
		if(a[i].b!=a[x].b){
			if(a[i].a-a[x].a>=0){
				sum+=a[x].a;
				a[i].a-=a[x].a;
				i-=1;
			}
			else{
				sum+=a[i].a;
				a[x].a-=a[i].a;
				x++;
			}
			x-=1;
		}
	}
	cout<<sum;
	return 0;
}
