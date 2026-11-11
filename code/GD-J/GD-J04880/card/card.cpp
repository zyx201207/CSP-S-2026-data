#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int> v;
int a[500005],count[500005],bj[500005];
bool vis[500005],b[500005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and,out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	for(int i=0;i<n;i++){
		if(vis[a[i]]==1){
			for(int j=bj[i];j<i;j++){
				b[j]=1;
			}
		}
		v.push_back(a[i]);
		vis[a[i]]=1;
		bj[vis[a[i]]]=i;
	}
	for(int i=0;i<n;i++){
		
	}
	for(int i=0;i<m;i++){
		cout<<count[i]<<" ";
	}
}
