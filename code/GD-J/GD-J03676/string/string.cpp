#include <bits/stdc++.h>
using namespace std;
long long a,c,l,r;
struct yz{
	long long b;
	char s;	
}ar[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for (int i=1;i<=a;i++){
		cin>>ar[i].b>>ar[i].s;
	}
	l=1;
	r=a;
	while(l<=r){
		if (ar[l].s==ar[r].s){
			ar[l].b-=min(ar[l].b,ar[r].b);
			ar[r].b-=min(ar[l].b,ar[r].b);
		}else{
			c+=min(ar[l].b,ar[r].b);
			ar[l].b-=min(ar[l].b,ar[r].b);
			ar[r].b-=min(ar[l].b,ar[r].b);
		}
		if (ar[l].b==0){
			l++;
		}
		if (ar[r].b==0){
			r--;
		}
	}
	cout<<c;
	return 0;
}
