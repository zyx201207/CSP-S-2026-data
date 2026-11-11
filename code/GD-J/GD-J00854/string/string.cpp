#include<bits/stdc++.h>
using namespace std;
struct t{
	long long a;
	char b;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	long long n,z=0;
	cin>>n;
	t a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
	int i=1,j=n;
	while(i!=j&&j>i){
		if(a[i].b!=a[j].b){
			z+=min(a[i].a,a[j].a);
		}
		if(a[i].a<a[j].a){
			a[j].a-=a[i].a;
			i++;
		}else if(a[i].a>a[j].a){
			a[i].a-=a[j].a;
			j--;
		}else{
			i++;
			j--;
		}
	}
	cout<<z;
	return 0;
} 
