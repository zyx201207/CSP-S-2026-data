#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m,a[N],ans[N];
vector<int>vec;
pair<int,int> gsr(int x){
	int f=0,id;
	for(int i=1;i<=vec.size();i++){
		if(vec[i]==x){
			f=1;
			id=i;
			break;
		}	
	}
	return make_pair(f,id);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	vec.resize(n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int round=1;round<=n;round++){
		for(int i=round;i<=n;i++){
			if(i!=round){
				auto tmp=gsr(a[i]);
				int check=tmp.first;				
				if(check){
					int idx=tmp.second;
					for(int j=vec.size();j>=idx;j--)
						vec.pop_back();
				}				
			}
			vec.push_back(a[i]);
		}
		for(int &u:vec)
			ans[u]++;
		vec.clear();		
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
