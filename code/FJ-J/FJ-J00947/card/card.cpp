#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500010],ans[300001],t[500010];
stack<int>s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]==a[j+1]){
				continue;
			}
			if(t[a[j]]==0){
				s.push(a[j]);
				t[a[j]]++;
			}else{
				while(s.size()){
					if(s.top()==a[j]){
						t[a[j]]--;
						s.pop();
						break;
					}else{
						t[s.top()]--;
						s.pop();
					}
				}
				s.push(a[j]);
				t[a[j]]++;
			}
		}
			for(int i=1;i<=m;i++){
//				cout<<t[i]<<" ";
				if(t[i]!=0){
					ans[i]++;
				}
			}
//			cout<<endl;
			fill(t,t+n+1,0);
			while(s.size()){
				s.pop();
			}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
