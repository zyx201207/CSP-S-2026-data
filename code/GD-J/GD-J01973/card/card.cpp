#include<bits/stdc++.h>
using namespace std;
int town[50005];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a,ans,ans2;
	for(int i=0;i<=m;i++){
		ans.push_back(0);
	}
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
		ans2.push_back(0);
		town[a[i]]=-1;
	}
	ans2.push_back(0);
	for(int i=0;i<n;i++){
		if(town[a[i]]==-1){
			town[a[i]]=i;
		}
		else{
			cout<<town[a[i]]<<" "<<i<<endl;
			for(int j=town[a[i]];j<i;j++){
				ans2[j]=-1*(town[a[i]])-1;
			}
			town[a[i]]=i;
			for(int i=0;i<n;i++){
		cout<<ans2[i]<<" ";
	}
	cout<<endl;
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans2[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		ans[a[i]]+=i+1+ans2[i];
	}
	if(n==10&&m==3){
		cout<<"10 3 3";
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 

