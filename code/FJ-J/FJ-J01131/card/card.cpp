#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int n,m,a[200010],id[30010]={},sum[30010]={},huh[30010];
bool v[30010]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++) v[i]=0,id[i]=0;
		for (int i=1;i<=m;i++) huh[i]=0;
		for (int i=k;i<=n;i++){
			huh[a[i]]++;
			if (v[a[i]]==0) v[a[i]]=1,id[a[i]]=i;
			else{
				v[a[i]]=0;
				for (int j=id[a[i]];j<i;j++) huh[a[j]]--;
				id[a[i]]=0;
			}
		}
		for (int i=1;i<=m;i++) if (huh[i]>0){
			sum[i]++;
			//cout<<i<<" "<<huh[i]<<endl;
		}
		//cout<<endl;
	}
	for (int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
/*
????????????
*/
