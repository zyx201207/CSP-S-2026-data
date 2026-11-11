#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int l[n+1],ans[n+1];
	for(int i=0;i<n;i++){
		cin>>l[i];
		ans[i]==0;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(l[i]==l[j]){
				k++;
			}
		}if(k%2==1){
			ans[l[i]]++;
		}
	}
	for(int i=2;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
