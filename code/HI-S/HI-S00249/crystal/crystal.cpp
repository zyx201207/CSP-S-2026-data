#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N];
int cnt=1;
int m;
int n; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n);//∂‘a£¨b√ª”√ 
	for(int i=1;i<n;i++){
		m-=abs((a[i+1]-a[i])*i);
		if(m>=0)cnt++;
		else break;
		
	}
	cout<<cnt;
	return 0; 
} 
