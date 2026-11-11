#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cnt,x,y;
char a[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>cnt>>a[i];
		if(a[i]==a[i-1]){
			ans+=cnt;
		}
		else{
			ans=cnt;
		}
		m+=cnt;
		x=max(x,ans);
	} 
	if(n%2==0){
		cout<<m-x;
	}
	else{
		cout<<m-x-1;
	}
	return 0;
} 
