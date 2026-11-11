#include<bits/stdc++.h>
using namespace std;
int n,q;
long long m,s[500005],x,y;
void dfs(int d){
	while(m){
		if(x<0&&y>n-1){
			return;
		}else if(s[x]<=s[y-1]&&x>=0&&m>=s[x]){
			m-=s[x];
			x--;
			q++;
		}else if(s[y-1]<=s[x]&&y<n&&m>=s[y-1]){
			m-=s[y-1];
			y++;
			q++;
		}else if(x>=0&&m>=s[x]){
			m-=s[x];
			x--;
			q++;
		}else if(y<n&&m>=s[y-1]){
			m-=s[y-1];
			y++;
			q++;
		}else{
			return;
		}
	}
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n);
	for(int i=0;i<n-1;i++){
		s[i]=s[i+1]-s[i];
	}
	x=n/2-1,y=n/2+1;
	dfs(n/2);
	cout<<++q;
	return 0;
} 
