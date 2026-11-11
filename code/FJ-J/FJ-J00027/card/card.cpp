#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m,a[500005],ans[300005]={0};
int li[300005]={0};
vector<ll>de;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		de.clear();
		de.push_back(0);
		for(int j=0;j<=m;j++) li[j]=0;
		for(int j=i;j<=n;j++){
			if(li[a[j]]==0){
				li[a[j]]=de.size();
				de.push_back(a[j]);
			}
			else{
				for(int k=de.size()-1;k>li[a[j]];k-=1){
					li[de[k]]=0;
					de.pop_back();
				}
				de.pop_back();
				li[a[j]]=de.size();
				de.push_back(a[j]);
			}
	    }
	    for(int j=1;j<=m;j++){
	    	if(li[j]!=0) ans[j]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
