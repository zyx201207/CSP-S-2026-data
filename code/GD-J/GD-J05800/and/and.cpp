#include<bits/stdc++.h>
using namespace std;
long long a[200010];
vector<long long> ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			vector<long long> aa,bb,cc;
			long long c=a[i],d=a[j],w=1,sum=0;
			while(c){
				int e=c%2;
				aa.push_back(e);
				c/=2;
			}
			while(d){
				int e=d%2;
				bb.push_back(e);
				d/=2;
			}
			if(aa.size()>bb.size()){
				for(long long k=0;k<=aa.size()-1;k++){
					if(aa[k]==1&&bb[k]==1){
						cc[k]=1;
					}else{
						cc[k]=0;
					}
				}
			}else{
				for(long long k=0;k<=bb.size()-1;k++){
					if(aa[k]==1&&bb[k]==1){
						cc[k]=1;
					}else{
						cc[k]=0;
					}
				}
			}
			for(long long kk=0;kk<=cc.size();kk++){
				sum+=cc[kk]*w;
				w*=2;
			}
			ans.push_back(sum);
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans[ans.size()-1];
	return 0;
}
