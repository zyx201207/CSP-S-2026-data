#include <bits/stdc++.h>
using namespace std;
int a[5000050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	stack<unsigned int long long> s;
	for(int i=0;i<n;i++) cin>>a[i];
	//vector<int> s;
	for(int i=0;i<n;i++){
		s.push(a[i]);
		for(int j=0;j<s.size()-1;j++){
			if(a[j]==a[i]){
				for(int k=a[j];k<=a[i-1];k++){
					s.pop();
				}
			} 
		}
	}
	return 0;
}
