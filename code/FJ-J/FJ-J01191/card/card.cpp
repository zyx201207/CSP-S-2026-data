#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int s[200001],a[200001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,flag1=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])flag1=0;
	}
	//Test 1 ~ 6, 24 pts
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int siz=v.size();
				for(int k=v.size()-1;k>=0;k--){
					if(a[j]==v[k])siz=k;
				}
				cout<<endl;
				while(v.size()>siz)v.pop_back();
				v.push_back(a[j]);
			}
			for(int k=0;k<v.size();k++){
				s[v[k]]++;
			}
			v.clear();
		}
		for(int i=1;i<=m;i++)
			cout<<s[i]<<" ";
	}
	//Test 7 ~ 9, 12 pts
	else if(flag1==1){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(j==i)v.push_back(a[j]);
				if(j>i&&a[j]!=a[j-1])v.push_back(a[j]);
			}
			for(int k=0;k<v.size();k++){
				//cout<<v[k]<<" ";
				s[v[k]]++;
			}
			//cout<<endl;
			v.clear();
		}
		for(int i=1;i<=m;i++)
			cout<<s[i]<<" ";
	}
	return 0;
}
//miao ~
//++ RP 
//RP ++ 
//36 pts
//All 265 pts
//suan4 shang4 gua4 fen1 da4 yue1 shi4 176(66.6%) neng2 yi1 ji2 (1=) ma1 ?
/*
265(100%) 
238.5(90%)
212(80%)
198.75(75%)
176(66.6%)
132.5(50%)
*/
//AFO
