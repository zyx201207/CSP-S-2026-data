#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	long long a[n+5],b[m+5]{0},b1=0;
	vector<int> v;
	vector<int> v2;
	for(int i=0;i<n;i++) cin>>a[i];
	
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=0;k<b1;k++){
				v2.push_back(v.front());
				if(v[k]==a[j]){
					b1=b1-k;
					v.clear();
					break;
				}
			}
			for(int c=0;c<b1;c++){
				v.push_back(v2.front());
				v2.pop_back();
			}
			b1++;
			v.push_back(a[j]);
		}
		while(!v.empty()){
			b[v.front()]++;
			v.pop_back();
		}
	}
	
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
	
}
