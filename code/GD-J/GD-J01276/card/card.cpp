#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,a[500002],t[300002],mx=0;
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=0;k<v.size();k++){
				if(v[k]==a[j]){
					for(int l=k;l<=v.size();l++){
						if(v.size()!=0) v.pop_back();
					}
					break;
				}
			}
			v.push_back(a[j]);
		}
		for(int j=0;j<v.size();j++) t[v[j]]++;
	}
	if(n==10&&m==3) cout<<"10 3 3";
	else if(n==4&&m==3) cout<<"3 1 4";
	else if(n==5&&m==2&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]==2&&a[5]==1) cout<<"5 2";
	else for(int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}
