#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=6e5+10; 
int n;
ll m,a[N],cry[N];
ll queue_window(){
	queue<int> q;
	ll maxn=1;ll cnt=0;
	ll length=0;
	for(int i=1;i<n;i++){
		q.push(i);
		length++;
		cnt+=length*cry[i];
		while(cnt>m){
			int t=q.front();
			q.pop();
			cnt=cnt-a[i+1]+a[t];
			length--;
		}
		maxn=max(maxn,length+1);
	}
	return maxn;
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n;cin>>m;
	for(int i=1;i<=n;i++) 
		cin>>a[i];
	sort(a+1,a+1+n);
	
	for(int i=1;i<n;i++)
		 cry[i]=a[i+1]-a[i];
	
	cout<<queue_window();
	
	return 0; 
}
