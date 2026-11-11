#include <bits/stdc++.h>
using namespace std;
const int maxer=3e5+10;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	int a[maxer];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int> placed;
	int num[maxer]={0};
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=i;k<j;k++){
				if(a[k]==a[j]){
					for(int y=k;y<j;y++){
						num[a[y]-1]--;
					}
				}
			}
			placed.push_back(a[j]);
			num[a[j]-1]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
