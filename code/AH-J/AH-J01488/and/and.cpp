#include<bits/stdc++.h>
using namespace std;
int f(int n){
	int cnt=1;
	for(int i=0;i<=30;i++){
		if(cnt*2>n) return i;
		cnt*=2;
	}
}
long long a[200008];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	long long ans=1,cnt=f(n-1),h=a[n-1];
	int flag=0;
	for(int i=n-2;i>=0;i--){
		if(f(a[i])==cnt){
			 ans++;
			 h&=a[i];
		}
		else{
			ans=1;
			cnt=f(a[i]);
			h=a[i]; 
		} 
		if(ans==m) {
			cout<<h<<endl;
			flag=1;
			break;
		} 
	}
	int s=a[n-1];
	if(flag==0){
		for(int i=n-2;i>=n-m;i--){
			s&=a[i];
		}
		cout<<s;
	}
	return 0;
} 
