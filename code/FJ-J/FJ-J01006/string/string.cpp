#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
struct node{
	int s;
	char ch;
}x[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].s>>x[i].ch;
	}
	int j=n;
	int ans=0;
	for(int i=1;i<=n;){
		if(x[i].ch==x[j].ch){
			if(x[i].s>=x[j].s){
				x[i].s-=x[j].s;
				x[j].s=0;
			}else{
				x[j].s-=x[i].s;
				x[i].s=0;
			}
		}else{
			ans+=min(x[i].s,x[j].s);
			if(x[i].s>=x[j].s){
				x[i].s-=x[j].s;
				x[j].s=0;
				
			}else{
				x[j].s-=x[i].s;
				x[i].s=0;
				
			}
		}
		if(x[i].s==0){
			i++;
		}
		if(x[j].s==0){
			j--;
		}
		if(i==j){
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
4
10 s
0 r
0 x
0 r
ans: 29
*/
