#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int id;char c;
}a[200005];
int b[100000];
void erfen(int n){
	int l=1,r=n;
	int cnt=0;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].id<a[r].id){
				a[r].id-=a[l].id;
				cnt+=a[l].id;
				l++;
			}else if(a[l].id>a[r].id){
				a[l].id-=a[r].id;
				cnt+=a[r].id;
				r--;
			}else{
				cnt+=a[r].id;
				l++;
				r--;
			}
		}else{
			if(a[l].id<a[r].id){
				a[r].id-=a[l].id;
				l++;
			}else if(a[l].id>a[r].id){
				a[l].id-=a[r].id;
				r--;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<cnt;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		a[i].id=x;
		a[i].c=c;
	}
	erfen(n);
	return 0;
}
