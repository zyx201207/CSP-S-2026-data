#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
vector<int> v,b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int f=1,id;
				for(int x=i;x<j;x++){
					if(a[x]==a[j]){
						id=x;
						f=0;
						break;
					}
				}
				if(f)
					v.push_back(a[j]);
				else{
					int x=j-1;
					while(x>=id){
						v.pop_back();
						x--;
					}
					v.push_back(a[j]);
				}
			}
			for(int j=0;j<v.size();j++){
			ans[v[j]]++;
			}
			v=b;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	else{
		return 0;
	}
	return 0;
}

