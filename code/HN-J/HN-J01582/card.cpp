#include<bits/stdc++.h>
using namespace std;
int n,m;
vector <int> arr;
vector <int> num;
vector <int> k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		while(num.size()!=0){
			num.pop_back();
		}
		num.push_back(arr[i]);
		for(int j=i+1;j<n;j++){
			int x=num.size()-1;
			while(x!=-1){
				if(num[x]==arr[j]){
					for(int y=j;y>x;y--){
						num.pop_back();
						x=-1;
					}
				}
				x--;
			}
			num.push_back(arr[j]);
		}
		for(int j=0;j<num.size();j++){
			for(int h=1;h<=m;h++){
				if(num[j]==h){
					k[h]++;
				}
			}
		}
	}
	/**/
	cout<<1;
	for(int i=0;i<m;i++){
		cout<<k[i]<<" ";
	}
	return 0;
}
