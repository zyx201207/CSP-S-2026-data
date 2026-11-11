#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+5;
const int inf=INT_MAX;
const ll lnf=LLONG_MAX;
using namespace std;

struct node{
	int x;
	char c;
}a[N];

int n,l=1,r;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}else if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				ans+=a[r].x;
				r--;
			}else if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				ans+=a[l].x;
				l++;
			}else{
				ans+=a[l].x;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
