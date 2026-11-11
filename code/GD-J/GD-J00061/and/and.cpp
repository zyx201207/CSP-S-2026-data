#include <bits/stdc++.h>
using namespace std;

int a[200005];
stack<int> d;
int v;

bool ch(int x){
	if(x==1){
		return 1;
	}
	if(x%2!=0){
		return 0;
	}
	return ch(x/2);
}

void dis(){
	while(!d.empty()){
		if(!ch(d.top())){
			d.pop();
		}else{
			v=max(v,d.top());
			d.pop();
		}
	} 
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%2==0){
			d.push(a[i]);
		}
	}
	if(m==1){
		int mxa=0;
		for(int i=0;i<n;i++){
			mxa=max(mxa,a[i]);
		}
		cout<<mxa;
		return 0;
	}
	dis();
	for(int i=0;i<n;i++){
		if(a[i]==v){
			a[i]=0;
		}
	}
	sort(a+0,a+n);
	long long ans=a[n-1];
	for(int i=n-2;i>=n-m;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
