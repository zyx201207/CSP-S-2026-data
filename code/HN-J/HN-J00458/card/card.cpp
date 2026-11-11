#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int number[N];
int ans[N];
int hh;
int tt;
int q[N];
vector<vector<int> > pos(N);
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		pos[a[i]].push_back(i) ;
		
	}
	for(int i = 1;i<=m;i++){
		number[i]=pos[i].size(); 
	}
	int cnt=0;
	for(int j =1;j<=n;j++){
		
		for(int i = j;i<=n;i++){
			ans[a[i]]++;
//			cout<<a[i]<<" ";
			if(number[a[i]]>1){
				i=pos[a[i]][pos[a[i]].size()-1];
			}
			
		}
		number[a[j]]--;
	}
	for(int i =1;i<=m;i++){
		if(i!=1) cout<<" ";
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
