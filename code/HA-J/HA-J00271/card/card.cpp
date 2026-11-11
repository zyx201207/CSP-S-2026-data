#include <bits/stdc++.h>
using namespace std;
int a[500005];
int cs[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=100005;i++){
		cs[i]=0;
	}
	set<int> st;
	int n,m;
	cin >>n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int j=1;j<=m;j++){
		st.clear();
		for(int i=j;i<=n;i++){
			if(st.find(a[i])!=st.end()){
				st.clear();
				
				st.insert(a[i]);
			}
			else {
				st.insert(a[i]);
			}
		}
		for(int k=1;k<=m;k++){
			if(st.find(k)!=st.end()){
				cs[k]++;
				
			}
		}
		
	}

	
	for(int i=1;i<=m;i++){
		
		cout << cs[i] << ' ';
		
		
	}
	return 0;
}
