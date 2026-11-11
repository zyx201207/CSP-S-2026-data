#include<bits/stdc++.h>
using namespace std;
int n,m,num;
vector<int> v;
int ans[300009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>num;
    	v.push_back(num);
	}
	for(int j=0;j<n;j++){
	vector<int> v1,v2;
		for(int i=j;i<v.size();i++){
			v2.push_back(v[i]);
		}
		int vs=0;
		while(vs<n-j){
			int k=0;
			if(v2[k]!=0){
			int a=v[k];
			v2.push_back(a);
			vs++;
			k++;
			}
			for(int w=0;w<v2.size();w++){
				if(v2[w]==v2[v2.size()-1]){
//					cout<<"'"<<v2[w]<<"'"<<" ";
					for(int p=w;p<v2.size();p++){
						v2[p]=0;
					}
				}
			}
		}
		for(int j=0;j<v2.size();j++){
			if(v2[j]!=0){
				ans[v2[j]]++;
			}
		}
	}
	int js=0;
	for(int i=0;i<=300009;i++){
		if(ans[i]!=0){
			cout<<ans[i];
			js++;
		}
		if(js==m){
			return 0;
		}
	}
	return 0;
}
