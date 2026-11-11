#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int x;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int i=1,j=n,ans=0;
	while(i<j){
		if(a[i].c!=a[j].c) ans+=min(a[i].x,a[j].x);
		if(a[i].x<a[j].x){
			a[j].x-=a[i].x;
			i++;
		}
		else if(a[i].x>a[j].x){
			a[i].x-=a[j].x;
			j--;
		}
		else{
			i++,j--;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
