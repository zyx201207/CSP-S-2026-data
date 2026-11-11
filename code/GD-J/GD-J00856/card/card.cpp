#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[500010];
long long ans[300010];
string desk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(find(desk.begin(),desk.end(),a[j])!=desk.end()){
				desk="";
			}
			desk+=a[j];
		}
		
		for(int j=1;j<=m;j++){
			if(find(desk.begin(),desk.end(),j+'0')!=desk.end()){
				ans[j]++;
			}
		}
		
		desk="";
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
