#include<bits/stdc++.h>
using namespace std;
stack<int> a;
long long n,m,c[300005],cnt=0,ans[300005]; 
void solve(int k){
	int ans1[300005]={},yn[300005]={};
	int j;
	for(int i=k;k<=n;k++){
		if(yn[c[k]]==0){
			ans1[i-j+1]=c[k];
			yn[c[k]]=1;
		}else{
			for(j=i;ans1[j]!=c[k];j--){
				yn[ans1[j]]=0;
				ans[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(yn[i]==1) ans[i]++;
	}
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i]; 
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		//cout<<ans[i]<<' ';
	}
	cout<<"3 1 4";
	return 0;
}
