#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int a[500005];
long long cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			//cout<<"//i="<<i<<endl;
			//cout<<"a[i]="<<a[i]<<endl;
			
			for(int j=0;j<v.size();j++){
				if(v[j]==a[i]){
					
					while(v[v.size()-1]!=a[i]){
						v.pop_back();
					}
					v.pop_back();
					break;
				}
			}
			v.push_back(a[i]);
		}
		for(int i=0;i<v.size();i++){
			cnt[v[i]]++;
			
		}
		while(!v.empty()){
			v.pop_back();
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
