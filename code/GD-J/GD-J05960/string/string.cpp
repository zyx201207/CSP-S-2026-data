#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
struct node{
	ll x;
	char c;
}a[10000086];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i].x>>a[i].c;
	}
	ll cnt=0,i=0,j=n-1;
	while(i<j){
		if(a[i].x==a[j].x){
			if(a[i].c!=a[j].c){
				cnt+=a[i].x;
			}
			i++;
			j--;
		}else if(a[i].x>a[j].x){
			if(a[i].c!=a[j].c){
				cnt+=a[j].x;
			}
			a[i].x-=a[j].x;
			j--;
		}else{
			if(a[i].c!=a[j].c){
				cnt+=a[i].x;
			}
			a[j].x-=a[i].x;
			i++;
		}
	}
	cout<<cnt;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
