#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],aa,bb;
vector<int> s;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.push_back(a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(s[n-1]==s[n]){
		ans[s[n]]++;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			aa++;
		}
		else{
			bb++;
		}
	}
	if((s[n-1]!=s[n])&&((s[n]==1&&aa%2==1)||(s[n]==2&&bb%2==1))){
		ans[s[n]]++;
		ans[s[n-1]]++;
	}
	else{
		ans[s[n]]++;
	}
	for(int i=1;i<=n;i++){
		if(ans[i]){
			cout<<ans[i];
		}
	}
	return 0;
}
