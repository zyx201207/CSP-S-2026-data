#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int flag[M],times[M];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		v=vector<int>();
		memset(flag,0,sizeof(flag));
		for(int j=i;j<=n;j++){
			if(!flag[a[j]]){
				flag[a[j]]=1;
				v.push_back(a[j]);
			//	for(auto it:v) cout<<it<<" "; 
			}
			else{
				auto it=v.end()-1;
				int cur=*it; 
				while(cur!=a[j]){
					v.pop_back();
					auto is=v.end()-1;
					cur=*is;
				}
				v.pop_back(); 
				v.push_back(a[j]);
				//for(auto it:v) cout<<it<<" "; 
			}
			//cout<<endl;
		}
		for(auto it:v){
//			cout<<it<<" ";
			times[it]++;
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<times[i]<<" ";
	}
	return 0;
}

