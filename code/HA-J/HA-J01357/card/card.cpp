#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005];
int con[500005];
vector<int> v;
bool is_you(int s,int t){
	for(int i = s;i < v.size();i++){
		if(v[i] == t){
			return false;
		}
	}
	return true;
}
int main(){
	cin.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	for(int i = 0;i < n;i++){
		for(int j = i;j < n;j++){
			if(is_you(i,arr[j])){
				v.push_back(arr[j]);
			}else{
				int t = j;
				while(arr[t-1] != arr[j]){
					v.pop_back();
				}
			}
		}
		for(int j = i;j < v.size();j++){
			for(int l = 0;l < m;l++){
				if(v[j] == arr[l]){
					con[l]++;
				}
			}
		}
	}
	for(int i = 0;i < m;i++){
		cout << con[i] << " ";
	}
	return 0;
}/*
4 3
1 2 1 3
*/

