#include <bits/stdc++.h>
using namespace std;
struct zimu{
	long long g;
	char z;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	if(n<=1){
		cout<<0;
		return 0;
	}
	zimu zm[200005];
	for(int i=1;i<=n;i++){
		cin>>zm[i].g>>zm[i].z;
	}
	int c=0;
	for(int i=1;i<n;i++){
		if(zm[i].z!=zm[i+1].z)c=1;
	}
	if(c==0){
		cout<<0;
		return 0;
	}
	int zw=0;
	for(int i=1;i<=n;i++){
		zw+=zm[i].g;
	}
	if(zw==2){
		cout<<0;
		return 0;
		}
	cout<<zw/2;
	return 0;
}
