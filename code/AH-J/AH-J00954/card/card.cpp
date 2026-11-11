#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
#define ll long long
using namespace std;
const string adsg="card";

int main(){
	freopen((adsg+".in").c_str(),"r",stdin);
	freopen((adsg+".out").c_str(),"w",stdout);
	int n,m;cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;i++){
			a[j]+=(n-j+1);
		}
	}for(int i=1;i<=n;i++){
		cout<<n[i];
	}
}
