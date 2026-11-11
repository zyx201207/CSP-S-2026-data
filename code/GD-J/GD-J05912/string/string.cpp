#include<bits/stdc++.h>
using namespace std;
struct node{
	int ll;
	char unit;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,h=0,s=0,k=0;
	cin>>n;
	node a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].ll>>a[i].unit;
		h+=a[i].ll;
	}
	for(int i=0;i<n;i++){
		s+=a[i].ll;
		if(h/2<=s){
			k=i;
			break;
		}
	}
	h=0,s=0;
	for(int i=0;i<=k;i++){
		if(a[i].unit!=a[n-i-1].unit&&i==k){
			h+=max(a[i].ll,a[n-i-1].ll)-s;
			s+=abs(a[i].ll-a[n-i-1].ll);
		}
	}
	cout<<h;
	return 0;
}
