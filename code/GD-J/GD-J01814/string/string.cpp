#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int N = 1e6 + 5; 

struct node{
	int num;
	char s;
}a[N];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
	}
	int l=1,r = n,ans=0;
	while(1){
		if(a[l].s==a[r].s){
			if(a[l].num<a[r].num){
				a[r].num-=a[l].num;
				l++;
			}
			else if(a[l].num==a[r].num){
				l++,r--;
			}
			else {
				a[l].num-=a[r].num;
				r--;
				
			}
		}
		else {
			if(a[l].num<a[r].num){
				ans+=a[l].num;
				a[r].num-=a[l].num;
				l++;
				
			}
			else if(a[l].num==a[r].num){
				ans+=a[l].num;
				l++,r--;
			}
			else {
				ans+=a[r].num;
				a[l].num-=a[r].num;
				r--;
				
			}
		}
		if(l>=r){
			break;
		} 
	}
	cout<<ans;
	return 0;
} 
