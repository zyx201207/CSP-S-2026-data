#include<bits/stdc++.h>
using namespace std;
struct node{
	long long sl;
	char zm;
} a[200005];
long long book[30];
string sd;//6*4+-
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>a[i].sl>>a[i].zm;
	}
	int l=1,r=n;
	bool flag=0;
	while(l<=r){
		if(a[l].sl!=a[r].sl||a[l].zm!=a[r].zm){
			long long zl=0;
			long long mx=-1;
			for(int i=1;i<=n;i++){
				book[int(a[i].zm-96)]+=a[i].sl;
				mx=max(mx,book[int(a[i].zm-96)]);
				zl+=a[i].sl;
			}	
			if(zl%2==1){
				zl-=mx;
				if(a[0].sl>=zl/2) zl-=1;
				cout<<zl;
			}
			else{
				zl-=mx;
				cout<<zl;
			}
			return 0;
		}
		l++;
		r--;
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
}
