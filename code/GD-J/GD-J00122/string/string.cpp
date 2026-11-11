#include<bits/stdc++.h>
using namespace std;
int cnt;
struct node{
	int lon;
	char a;
}c[100010];
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,l=1,r;
	int ans=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].lon>>c[i].a;
		s+=c[i].lon;
	}
	for(int i=1;i<=n;i++){
		if(c[i].a==c[i+1].a){
			cnt++;
		}
	}
	if(cnt==n){
		cout<<0;
		return 0;
	} 
	r=s;
	while(l<r){
		if(c[l].a!=c[r].a){
			ans++;
			l++;
			r--;
		}else if(c[l].a==c[r].a){
			l++;
			r--;
		} 
	}
	cout<<ans;
	
}
