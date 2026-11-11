#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int l=5e5+5,O=3e5+5;
int n,m,a[l],bj[O];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack <int> s;
		set <int> st;
		for(int j=i;j<=n;j++){
			if(st.count(a[j])){
				while(1){
					int num=s.top();
					s.pop();
					st.erase(num);
					if(num==a[j]){
						break;
					}
				}
			}
			st.insert(a[j]);
			s.push(a[j]);
		}
		while(!s.empty()){
			int num=s.top();
			s.pop();
			st.erase(num);
			bj[num]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<bj[i]<<" ";
	}
	return 0;
} 
