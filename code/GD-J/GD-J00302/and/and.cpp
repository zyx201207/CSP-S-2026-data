#include<bits/stdc++.h>
using namespace std;



int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int shu[n];
	for(int i=0;i<n;i++){
		cin>>shu[i];
	}
	vector<int> numb;
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				numb.push_back(shu[i]&shu[j]);
			}
		}	
	}else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					numb.push_back(shu[i]&shu[j]&shu[k]);				
				}
			}
		}
	}
	int max=0;
	for(int i=0;i<numb.size();i++){
		if(max<numb[i]){
			max=numb[i];
		}
	}
	cout <<max;
	fclose(stdin);
	fclose(stdout);
}
