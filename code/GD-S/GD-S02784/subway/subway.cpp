#include<bits/stdc++.h>
using namespace std;

int tesNo,line_n,sta_n,exup,plan_n;
int time_io[500005];
vector<vector<int> >route,time_ex;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	
	cin>>tesNo>>line_n>>sta_n>>exup>>plan_n;
	for(int i=1;i<=sta_n;i++)cin>>time_io[i];
	for(int i=1;i<=line_n;i++){
		long long s;
		cin>>s;
		for(int j=1;j<=s*2;j++){
			int x;
			cin>>x;
			route[i].push_back(x);
		}
	}
	
	
	
	
	
	
	if(tesNo==0)cout<<'\n'<<"It's just an example.Remember to delete the // before freopen."<<'\n';
}
