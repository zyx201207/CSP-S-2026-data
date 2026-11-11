#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;int w[m+10]={},a[n+10]={},b[m+10]={},h[m+10]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}vector<int>c;
	for(int i=1;i<=n;i++){
		memset(h,0,sizeof(h));
		memset(w,0,sizeof(h));
		for(int k=0;k<c.size();k++){
			w[c[k]]=1;
		}
		for(int j=i;j<=n;j++){
			if(!w[a[j]]){
				c.erase(lower_bound(c.begin(),c.end(),a[j]),c.end());
			}
			w[a[j]]=1;
			c.push_back(a[j]);
		}
		for(int k=0;k<c.size();k++){
			if(!h[c[k]]){
				b[c[k]]++;
				h[c[k]]=1;
			}
			
		}
	}
	for(int k=1;k<=m;k++){
		cout<<b[k]<<' ';
	}
	return 0;
}
