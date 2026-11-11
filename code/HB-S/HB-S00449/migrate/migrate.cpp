#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<pair<int,int>>> se;
vector<int> fe;
void mian(int x,int s,int d){
	if(x<0)return;
	for(int i=0;i<x;i++){
		if(se[i][x].first!=-1){
			if(se[i][s].first>d+se[i][x].first||se[i][s].first==-1){
				se[i][s].first=d+se[i][x].first;
				se[i][s].second=se[i][x].second;
				mian(i,s,d+se[i][x].first);
			}if(se[i][s].first==d+se[i][x].first)
				se[i][s].second+=se[i][x].second;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int iii=0;iii<t;iii++){
		int d;
		cin >> n >> d;
		vector<pair<int,int>> ssss;pair<int,int>sss;
		sss.first=-1,sss.second=0;
		for(int i=0;i<n;i++)ssss.push_back(sss);
		for(int i=0;i<n;i++)se.push_back(ssss);
		int x[n];
		for(int i=0;i<n;i++)cin >> x[i];
		for(int i=0;i<n;i++){
			bool b=true;
			for(int j=i+1;j<n;j++){
				
				if(x[j]-x[i]>d){
					fe.push_back(j-1);
					b=false;
					break;
				}
				se[i][j].first=1,se[i][j].second=1;
			}
			if(b)fe[i]=n-1,se[i][n-1].first=1,se[i][n-1].second=1;
		}
		for(int i=n-1;i>-1;i--)mian(i,i,0);
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(se[i][j].second==2)
					ans++;
		cout << ans-n<<endl;
	}
	return 0;
}
