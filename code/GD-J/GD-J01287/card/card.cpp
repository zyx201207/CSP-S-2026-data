#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int a[MAXN]={};
int cnt[MAXN]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		vector<int> v;
		v.push_back(a[i]);
		for(int j=i+1;j<=n;j++){
			bool flag=0;
			for(int k=0;k<v.size();k++){
				if(a[j]==v[k]){
					for(int l=k;l<v.size();l++){
						v.pop_back();
					}
					flag==1;
				}
//				cout<<v[k]<<endl; 
			}
			if(!flag) v.push_back(a[j]);
		}
		for(int j=0;j<v.size();j++){
			cnt[v[i]]++;
//			cout<<v[i]<<" ";
		}
		cout<<endl;
//		cout<<v.size();
	}
	for(int i=1;i<=m;i++) cout<<cnt[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
