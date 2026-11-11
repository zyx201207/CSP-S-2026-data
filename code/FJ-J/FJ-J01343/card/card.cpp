#include<bits/stdc++.h>
using namespace std;

const int maxn=500005, maxm=300005;

int n,m;
int a[maxn],numt[maxm],ans[maxm];
bool flag[maxm];

vector<int> pl[maxm];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		++numt[a[i]];
	}
	int cnt=0, ptr=n;
	while(cnt<m && ptr>0){
		if(flag[a[ptr]]){
			ptr--;
			continue;
		}
		flag[a[ptr]]=true;
		cnt++;
		if(ptr==n){
			pl[a[ptr]].push_back(a[ptr]);
		}else{
			pl[a[ptr]].push_back(a[ptr]);
			for(int i=0;i<pl[a[ptr+1]].size();i++){
				pl[a[ptr]].push_back(pl[a[ptr+1]][i]);
//				cout<<"push"<<a[ptr]<<" "<<pl[a[ptr+1]][i]<<"\n";
			}
		}
		ptr--;
	}
//	cout<<cnt<<" "<<ptr<<"\n";
//	for(int i=1;i<=m;i++){
//		for(int j=0;j<pl[i].size();j++){
//			cout<<pl[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<pl[i].size();j++){
			ans[pl[i][j]]+=numt[i];
//			cout<<pl[i][j]<<": +"<<numt[i]<<"\n";
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
