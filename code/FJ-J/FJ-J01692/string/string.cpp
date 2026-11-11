#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	ll num;
	char ch;
}a[2*100000+10];
ll anum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
	}
	ll l=1,r=n;
	while(l<r){
		if(a[l].ch!=a[r].ch){
			if(a[l].num>=a[r].num){
				anum+=a[r].num;
				a[l].num-=a[r].num;
				r--;
			}
			if(a[l].num<a[r].num){
				anum+=a[l].num;
				a[r].num-=a[l].num;
				l++;
			}
		}
		else{
			if(a[l].num>a[r].num){
				a[l].num-=a[r].num;
				r--;
			}
			if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				l++;
			}
			else if(a[l].num==a[r].num){
				l++;
				r--;
			}
		}
		if(a[l].num==0)l++;
		if(a[r].num==0)r--;
	}
	cout<<anum;
	return 0;
}
