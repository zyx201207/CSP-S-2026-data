//Ìï•×¶÷GZ-J00051
#include<bits/stdc++.h>
using namespace std;
int a[500005],used1[500005],first1[300005],sum1[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> desk;
		int cur=i;
		while(cur<=n){
			if(used1[cur]==0){
				desk.push_back(a[cur]);
				used1[cur]=1;
				first1[a[cur]]=i;
		    }
			else{
				for(int j=1;j<=desk.size()-first1[a[cur]];j++){
					desk.pop_back();
				}
				desk.push_back(a[cur]);
			}
			cur++;
		}
		for(int j=1;j<=m;j++){
			for(int k=0;k<desk.size();k++){
				if(desk[k]==j){
					break;
				}
			}
			sum1[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum1[i]<<" ";
	}
	return 0;
} 
