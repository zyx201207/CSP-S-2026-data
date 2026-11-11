#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int ans[m]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}for(int i=0;i<n;i++){
		vector<int>t;
		int id[m];
		for(int j=0;j<m;j++){
			id[j]=-1;	
		}for(int j=0+i;j<n;j++){
			int temp=a[j];
			if(id[temp]==-1){
				t.push_back(temp);
				id[temp]=t.size()-1;
			}else{
				for(int k=id[temp]+1;k<t.size();k++){
					id[t[k]]=-1;	
				}t.erase(t.begin()+id[temp]+1,t.end());
			}
		}for(int j=0;j<t.size();j++){
			ans[t[j]]++;
		}				
	}for(int i=0;i<m;i++){
		cout<<ans[i]<<" ";
	}return 0;
	
}	
