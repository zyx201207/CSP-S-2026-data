#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,sum;
struct jasmine{
	ll a;
	char c;
}a[200055];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	ll l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c){
			if(a[l].a>a[r].a){
				sum+=a[r].a;
				a[l].a-=a[r].a;
				r--;
			}else if(a[l].a<a[r].a){
				sum+=a[l].a;
				a[r].a-=a[l].a;
				l++;
			}else{
				sum+=a[l].a;
				l++;
				r--;
			}
		}else{
			l++;
			r--;
		}
	}
	cout<<sum;
	return 0;
}
