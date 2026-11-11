#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[300005];
bool chk(){
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			return false;
		}
	}return true;
}signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(chk()){
		for(int i=1;i<=n;i++){
			int i1=i;
			sum[a[i]]=sum[a[i-1]];
			while(i<=n&&a[i]==a[i1]){
				i++,sum[a[i1]]++;
			}i--;
			cout<<sum[a[i1]]<<" ";
		}
	}else{
		for(int i=1;i<=n;i++){
			vector<int>vec;
			for(int j=i;j<=n;j++){
				auto p=find(vec.begin(),vec.end(),a[j]);
				if(*p==a[j]){
					while(p!=vec.end()){
						vec.erase(p);
					}
				}vec.push_back(a[j]);
			}for(vector<int>::iterator j=vec.begin();j!=vec.end();j++){
				sum[*j]++;
			}
		}for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
	}
}
