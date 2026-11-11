#include<bits/stdc++.h>
using namespace std;
unsigned long long ans;
int n,l,r;
struct node{
	int a;
	char c;
}a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	while(r>l){
		if(a[l].c!=a[r].c){
			ans+=min(a[l].a,a[r].a);
		}
		if(a[l].a>a[r].a){
			a[l].a-=a[r].a;
			r--;
		}else if(a[l].a<a[r].a){
			a[r].a-=a[l].a;
			l++;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
