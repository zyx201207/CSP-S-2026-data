#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
char maze[900000010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		int x;
		char ch;
		cin>>x>>ch;
		while(x--){
			sum++;
			maze[sum]=ch;
		}
	}
	if(sum%2==0){
		for(int i=sum/2+1,cnt=1;i<=sum;i++,cnt+=2){
			if(maze[i]!=maze[i-cnt]){
				ans++;
			}
		}
	}
	else{
		for(int i=sum/2+2,cnt=2;i<=sum;i++,cnt+=2){
			if(maze[i]!=maze[i-cnt]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

