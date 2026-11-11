#include<bits/stdc++.h>
using namespace std;
struct node{
	int sum;
	char x;
}a[200005];
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].sum>>a[i].x;
	int l=1,r=n;
	while(l<=r){
		if(a[l].x==a[r].x){
			if(a[l].sum!=a[r].sum){
				if(a[l].sum>a[r].sum)a[l].sum-=a[r].sum,r--;
				else a[r].sum-=a[l].sum,l++;
			}
			else l++,r--;
		}
		else {
			ans+=min(a[l].sum,a[r].sum);
			if(a[l].sum!=a[r].sum){
				if(a[l].sum>a[r].sum)a[l].sum-=a[r].sum,r--;
				else a[r].sum-=a[l].sum,l++;
			}
			else l++,r--;
		}
	}
	cout<<ans<<endl;
	return 0;
} 

