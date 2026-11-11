#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		a.push_back(j);
	}
	int ans=0;
	if(m==1){
		for(int i=0;i<n;i++){
			ans=a[i];
		}
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=a[i]&a[j];
			}
		}
	}
	if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					ans=a[i]&a[j]&a[k];
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
