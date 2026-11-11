#include<bits/stdc++.h>
using namespace std;
long long n,ans;
const long long N=2e5+10;
struct node{
	long long ge;
	string s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ge>>a[i].s;
	}
	long long l=1,r=n;
	while(l<=r){
		if(a[l].ge<a[r].ge){
			a[r].ge-=a[l].ge;
			if(a[l].s!=a[r].s){
				ans+=a[l].ge;
			}
			l++;
		}else if(a[l].ge==a[r].ge){
			if(a[l].s!=a[r].s) ans+=a[l].ge;
			l++;
			r--;
		}else{
			a[l].ge-=a[r].ge;
			if(a[r].s!=a[l].s){
				ans+=a[r].ge;
			}
			r--;
		}
	} 
	cout<<ans;
	return 0;
}
