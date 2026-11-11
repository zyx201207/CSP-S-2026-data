#include<bits/stdc++.h>
using namespace std;
vector<int> result;
void backtraveling(int m,vector<int> a,int index,int t,int i){
	if(i==a.size()) return;
	if(index==m){
		result.push_back(t);
		return;
	}
	backtraveling(m,a,index+1,int(t&a[i]),i+1);
	backtraveling(m,a,index,t,i+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	backtraveling(m,a,0,INT_MAX,0);
	int answer=0;
	for(int j=0;j<result.size();j++){
		answer=max(answer,result[j]);
	}
	cout<<answer;
	return 0;
}
