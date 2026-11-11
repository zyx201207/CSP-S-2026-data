#include<bits/stdc++.h>
using namespace std;
long long n,ans,p,f;
string s,c;
struct node{
	long long k;
	char e;
	};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	node a[200005];
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].k>>a[i].e;
	}
	int l=1,r=n;
	while(r+1!=l&&l!=r){
		if(a[l].e!=a[r].e){
			ans+=min(a[l].k,a[r].k);
			if(a[l].k<a[r].k){
				a[r].k=a[r].k-a[l].k;
				l++;
				}
			else if(a[l].k==a[r].k){
				l++;
				r--;
				}
			else {
				a[l].k=a[l].k-a[r].k;
				r--;
				}
			}
			else{
				if(a[l].k<a[r].k){
					a[r].k=a[r].k-a[l].k;
					l++;
				}
				else if(a[l].k==a[r].k){
					l++;
					r--;
					}
				else {
					a[l].k=a[l].k-a[r].k;
					r--;
				}
			}
		}
		cout<<ans;
	return 0;
}
