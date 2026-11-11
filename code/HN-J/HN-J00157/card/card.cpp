#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
stack<int>d;
bool s[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)s[j]=0;
		for(int j=i;j<=n;j++){
			if(s[a[j]]){
				s[a[j]]=1;
				while(d.size()){
					if(d.top()==a[j]){
						break;
					}
					else{
						s[d.top()]=0;
						d.pop();
					}
				}
			}
			else{
				s[a[j]]=1;
				d.push(a[j]);
			}
		}
		while(d.size()){
			ans[d.top()]++;
			d.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" "; 
	return 0;
}
