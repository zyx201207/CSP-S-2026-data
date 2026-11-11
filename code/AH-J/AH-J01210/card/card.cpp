#include<bits/stdc++.h>
using namespace std;
stack<int> a;
bool t[300005];
int n,m,num[500005],ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t[num[j]]==0){
				a.push(num[j]);
				t[num[j]]=1;
			}else{
				while(1){
					if(a.top()==num[j]){
						break;
					}
					t[a.top()]=0;
					a.pop();
				}
				
			}
		}
		for(int k=1;k<=m;k++){
			if(t[k]==1){
				ans++;
			}
		}
		
		while(!a.empty()){
			a.pop();
		}
		memset(t,0,m);
		cout<<ans<<" ";//while(1){}
		ans=0;
	}
	return 0;
}
