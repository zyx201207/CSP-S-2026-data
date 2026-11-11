#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int cnt=0,ans=0;
int n,a;
char c[50000005];


int main(){
	
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		cin>>a>>x;
		
		for(int j=cnt+1;j<=cnt+a;j++){
			c[j]=x;
		} 
		cnt+=a;
	}
	int l=1,r=cnt;
	while(l<=r){
		if(c[l]!=c[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	
	return 0;
}

