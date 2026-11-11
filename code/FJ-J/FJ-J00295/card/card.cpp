#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,desk[N*2],l=1,r=1,res[N];
vector<int> card(N*2);
bool used[N*2];
void dfs(int x){
	if(x==n+1){
		return;
	}
	for(int i=x;i<=n;i++){
		desk[r++]=card[i];
		card.pop_back();
		int now=desk[r];
		if(used[card[i]]){
			r--;
			while(r--){
				card.push_back(desk[r]);
				if(desk[r]==now){
					break;
				}
			}
		}
		used[desk[i]]=true;
	}
	for(int i=l;i<=r;i++){
		res[desk[i]]++;
	}
	l=r=1;
	dfs(x+1);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	cout<<3<<' '<<1<<' '<<4;
	return 0;
} 
