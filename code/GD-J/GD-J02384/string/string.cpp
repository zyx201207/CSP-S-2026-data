#include<bits/stdc++.h>
using namespace std;

struct node{
	long long cnt;
	char ch;
}a[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i].cnt >> a[i].ch;
	}
	int l=0,r=n-1;
	long long ans=0;
	while(l<=r){
		if(a[l].ch==a[r].ch){
			long long mi=min(a[l].cnt,a[r].cnt);
			a[l].cnt-=mi;
			if(a[l].cnt==0)l++;
			a[r].cnt-=mi;
			if(a[r].cnt==0)r--;
		}else{
			long long mi=min(a[l].cnt,a[r].cnt);
			ans+=mi;
			a[l].cnt-=mi;
			if(a[l].cnt==0)l++;
			a[r].cnt-=mi;
			if(a[r].cnt==0)r--;
		}
	}
	cout << ans;
	return 0;
}
