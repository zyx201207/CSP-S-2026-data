#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],sum[1000005];vector<long long> t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	   
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		t.clear();
		for(int j=i-1;j<n;j++){
			if(find(t.begin(),t.end(),a[j])!=t.end()){
				t.erase(find(t.begin(),t.end(),a[j]),t.end());
			}
			t.push_back(a[j]);
		}
		for(int j=1;j<=m;j++)sum[j]+=(find(t.begin(),t.end(),j)!=t.end());
		
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
} 
 
