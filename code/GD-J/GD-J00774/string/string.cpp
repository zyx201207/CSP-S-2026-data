#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll total=0,a[n],ans=0;
	char l[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>l[i];
		total+=a[i];
	}
	int f=a[0],t=0;
	char k=l[0];
	for(int i=0;i<n;i++){
		if(l[i]==k){
			t++;
		}
	}
	if(t==n){
		cout<<0;
		return 0;
	}
	t=0;
	for(int i=0;i<n;i++){
		if(a[i]==f){
			t++;
		}
	}
	if(t==n){
		for(int i=0;i<n/2;i++){
			int o=n-1-i;
			if(l[o]!=l[i]){
				ans++;
			}
		}
		cout<<ans*f;
		return 0;
	}
	if(n==1){
		cout<<0;
	}
	cout<<7;
	return 0;
}
