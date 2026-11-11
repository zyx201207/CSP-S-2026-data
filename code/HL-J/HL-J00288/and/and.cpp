#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	int ans=0;
	int k=0;
	for(int i=1;i<=n;i++){
		cin>>n;
		for(int i=1;i<=m;i++){
			 k=ans&n;
			if(k>ans){
				k=ans;
			}
		}
	}
	cout<<k;
	fclose(stdin);
    fclose(stdout);
    return 0;
	
}
