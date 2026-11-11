#include<bits/stdc++.h>
using namespace std;

int n,m;
string s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string max="0";
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		int x=s[i].size();
		if(x>max.size()) max=s[i];
		if(x==max.size()){
			for(int j=0;j<x;j++){
				if(s[i][j]>max[j]){
					max=s[i];
					break;
				}
			}
		}
	}
	cout<<max;
	return 0;
}
