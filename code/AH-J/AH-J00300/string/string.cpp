#include<bits/stdc++.h>
using namespace std;
int n;
int sum[200005];
char k[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sum[i]>>k[i];
	}
	int idx1=1,idx2=n;
	long long ans=0;
	while(1){
		if(idx1>=idx2)break;
		int ss=min(sum[idx1],sum[idx2]);
		//cout<<idx1<<" "<<idx2<<" "<<ss<<" "<<ans<<endl;
		if(k[idx1]!=k[idx2]){
			ans+=ss;
		}
		if(sum[idx1]>sum[idx2]){
			idx2--;
			sum[idx1]-=ss;
		}else{
			idx1++;
			sum[idx2]-=ss;
		}
	}
	cout<<ans;
	return 0;
}
