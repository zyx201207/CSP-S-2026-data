#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
string k;
ll sum=0;
struct node{
	ll s;
	char l;
};
node a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].l;
	}
	ll x=1;
	for(int i=n;i>=1;){
		if(a[x].s==0){
			x++;
		}
		if(a[i].l!=a[x].l){
			if(a[i].s<=a[x].s){
				sum+=a[i].s;
				a[x].s-=a[i].s;
				i--;
				continue;
			}
			else{
				sum+=a[x].s;
				a[i].s-=a[x].s;
				a[x].s=0;
			}
		}
		else{
			if(a[i].s<=a[x].s){
				a[x].s-=a[i].s;
				i--;
				continue;
			}
			else{
				a[i].s-=a[x].s;
				a[x].s=0;
			}			
		}
	}
	cout<<sum;
	return 0;
}