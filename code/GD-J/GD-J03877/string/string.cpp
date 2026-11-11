#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct o{
	ll s;
	char c;
};
o a[200020];
ll sum,n,l,r;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].s>>a[i].c;
	l=1,r=n;
	while(l<=r){
		if(a[l].c==a[r].c){
			if(a[l].s>a[r].s){
				a[l].s-=a[r].s;
				r--;
			}
			else if(a[l].s<a[r].s){
				a[r].s-=a[l].s;
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			sum+=min(a[l].s,a[r].s);
			if(a[l].s>a[r].s){
				a[l].s-=a[r].s;
				r--;
			}
			else if(a[l].s<a[r].s){
				a[r].s-=a[l].s;
				l++;
			}
			else{
				l++;
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
