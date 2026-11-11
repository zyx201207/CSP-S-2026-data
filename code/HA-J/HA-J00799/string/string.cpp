#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int cnt;
	char s;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].s;
	}
	int ans=0;
	for(int i=1,j=n;i<=j;){
		if(a[i].s==a[j].s){
			if(a[i].cnt==a[j].cnt){
				i++,j--;
			}
			else if(a[i].cnt<a[j].cnt){
				a[j].cnt-=a[i].cnt;
				i++;
			}
			else {
				a[i].cnt-=a[j].cnt;
				j--;
			}
		}
		else{
			if(a[i].cnt==a[j].cnt){
				i++,j--;
				ans+=a[i].cnt;
			}
			else if(a[i].cnt<a[j].cnt){
				a[j].cnt-=a[i].cnt;
				ans+=a[i].cnt;
				i++;
			}
			else{
				a[i].cnt-=a[j].cnt;
				ans+=a[j].cnt;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
