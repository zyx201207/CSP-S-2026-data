#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int c,t;
int n,k;
int a[N],b[N];
int T,ans = 0;
int s[2] = {};
void node(int d[N],int dist){
	for(int i = 1;i <= n - 1;i++){
		for(int j = 1;j <= n - 1;j++){
			d[i] = min(i,j);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i]>>b[i];
	for(int i = 1;i <= n - 1;i++){
		while(T--){
			for(int s = k;s <= 2;s++){
				if(i < s){
					a[s]= 0;
				}
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
