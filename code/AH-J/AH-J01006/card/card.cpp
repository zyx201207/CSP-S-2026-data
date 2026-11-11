#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50000];
int b[50000];
int ans[50000];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		
	}
	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			v.push_back(a[j]);
			if(b[a[i]] == 1){
				int mm = a[j];
				v.pop_back();
			    for(int s=j;s>=i;s--){
			    	if(a[s]!= mm){
			    		v.pop_back();
					}
					else{
						break;
					}
				}
			}
			else{
				b[a[i]] == 1;
			}
		}
	}
	for(int i = 0;i<m;i++){
		if(b[i] == 1){
			ans[i] ++;
		} 
		cout<<ans[i]<<" ";
	}
	
	return 0;
} 
