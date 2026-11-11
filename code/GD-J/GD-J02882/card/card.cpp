#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
vector<int> v;
int p;
int t[1000000];
int maxx=-1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	v.clear();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//v.clear();
			if(v.empty()){
				v.push_back(a[j]);
				//cout<<a[j]<<endl;
			}else{
				if(v[v.size()-1]<=a[j]){
					v.push_back(a[j]);
					//cout<<a[j]<<endl;
				}else{
					int c;
					for(int k=0;k<v.size();k++){
						if(a[j]<=a[k]){
							c=a[k];
							break;
						}
					}
					for(int k=c;k<=v[v.size()-1];k++){
						v.pop_back();
					}
					v.push_back(a[j]);
					//cout<<a[j]<<endl;
				}
			}
		}
		for(int j=0;j<v.size();j++){
			t[v[i]]++;
			//cout<<v[i]<<endl;
		}
		//cout<<endl;
	}
	for(int i=1;i<=maxx;i++){
			cout<<t[i]<<" ";
			//cout<<i<<" ";
	}
	return 0;
}
