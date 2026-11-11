#include<bits/stdc++.h>
using namespace std;
const int N=2*1e8+5;
int s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;cin>>n;
	int cnt=1;
	for(int i=1;i<=n;i++){
		int a1;
		char b1;
		cin>>a1>>b1;
		int k=(b1-'a');
		for(int j=cnt;j<=cnt+a1-1;j++){
			s[j]=k;	
		}
		cnt+=a1;
	}
	int k=cnt/2;
	int l=0,r=cnt;
	int ans=0;
	while(l<=r){
		if(s[l++]!=s[r--])ans++;
	}
	cout<<ans;
    return 0;
}

