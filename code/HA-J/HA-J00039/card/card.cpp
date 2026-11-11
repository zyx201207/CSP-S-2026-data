#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005];
int num[300005];
vector<int> lefts;
vector<int> rights;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		for(int j=1;j<i;j++){
			if(arr[i]==arr[j]){
				if(rights[rights.size()-1]<j){
					lefts.push_back(j);
					rights.push_back(i);
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		int num=0;
		for(int j=1;j<=n;j++){
			int cunzai=0;
			for(int k=j;k<=n;k++){
				if(arr[k]==i){
					cunzai++;
					for(int l=0;l<lefts.size();l++){
						if(lefts[l]<=k&&rights[l]>=k&&lefts[l]>=j){
							cunzai--;
						}
					}
				}
			}
			if(cunzai!=0){
				num++;
			}
		}
		cout<<num<<' ';
	}
	return 0;
}
