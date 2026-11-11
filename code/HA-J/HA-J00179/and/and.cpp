#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],ans=-1;
int n,m,cnt,idx;
int cmp(long long x,long long y) {
	return x>y;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	for (int i=0;i<n;i++)
	{
		int tmp=log2(a[i]);
		if (pow(2,tmp)!=a[i]){
			ans=a[i];
			cnt++;
			idx=i+1;
			break;
		}
	}
	if (ans==-1 and m!=1) {
		cout<<0;
		return 0;
	} else if (ans==-1 and m==1){
		cout<<a[0];
		return 0;
	}
	
	
	while(cnt<m and idx<n)
	{
		
		if (ans&a[idx]==0) {
			idx++;
			continue;
		}
		else {
			ans&=a[idx];
			idx++;
			cnt++;		
		}
	}
	if (cnt<m) cout<<0;
	else cout<<ans;

	
	
	return 0;
}
