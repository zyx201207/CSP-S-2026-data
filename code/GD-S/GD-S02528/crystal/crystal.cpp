#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
long long m;
long long a[500005];
struct node{
	int id;
	long long dis;
};
node b[500005];
bool cmp(node a,node b){
	return a.dis < b.dis;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long mid;
	if(n%2){
		mid=a[n/2+1];
		//int x=n/2+1;
	}else{
		mid=a[n/2];
		//int x=n/2;
	}
	for(int i=1;i<=n;i++){
		b[i].dis=max(mid-a[i],a[i]-mid);
	}
	sort(b+1,b+n+1,cmp);
	int x=1;
	while(m){
		if(b[x].dis<=m){
			m-=b[x].dis;
			ans++;
		}else{
			m-=m;
		}
		x++;
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
Oct31==Dec25?
 */
