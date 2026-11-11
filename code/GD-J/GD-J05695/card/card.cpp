#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	vector<int> a(n+1,0),ans(m+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m){
			s++;
		}
	}for(int i=n;i>=1;i--){
		vector<int> b;
		for(int j=i;j<=n;j++){
			for(int k=0;k<b.size();k++){
				if(b[k]==a[i]){
					b={};
					break;
				}
			}b.push_back(a[i]);
		}for(int k=0;k<b.size();k++){
			ans[b[k]]++;
		}
	}for(int i=2;i<=m;i++){
		ans[1]+=ans[i];
	}if(a[n]==m){
		ans[1]-=ans[m];
	}for(int i=1;i<=m-1;i++){
		cout<<ans[i]<<" ";
	}if(a[n]==m&&s%2==1){
		cout<<n;
	}else{
		cout<<ans[m]; 
	}
	return 0;
}
