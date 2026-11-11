//GZ-J00595 遵义市播州区保利小学 雷雨淳 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[n+5],b[m+5];
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		vector <int> q;
		for(int j=i;j<n;j++){
			if(!q.empty()){
				if(q.find(a[j])!=q.end()){
					while(1){
						if(q.pop()==a[j]){
							break;
						}
						q.erase(q.size()-1,1);
					}
				}
				else{
					q.push_back(a[j]);
				}
			}
			else{
				q.push_back(a[j]);
			}
		}
		for(int k:q){
			b[k]++;
		}	
	}
	for(int i=0;i<m;i++){
		cout<<b[i];
	}
}
