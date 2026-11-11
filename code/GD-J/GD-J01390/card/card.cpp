#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l[n+1];
	for(int i=1;i<n+1;i++){
		cin>>l[i];
	}
	int r[m+1];
	for(int i=1;i<=m;i++){
		r[i]=0;
	}
	for(int i=1;i<=n;i++){
		vector<int> t;
		t.clear();
		for(int j=i;j<n+1;j++){
			int b=-1;
			for(int p=0;p<t.size();p++){
				if(t[p]==l[j]){
					b=p;
					continue;
				}
			}
			if(b==-1){
				t.push_back(l[j]);
			}
			else{
				b=t.size()-b;
				for(int p=0;p<b-1;p++){
					t.erase(t.end());
				}
			}
		}
		for(int i=0;i<t.size();i++){
			r[t[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<r[i]<<" ";
	}
	return 0;
}
