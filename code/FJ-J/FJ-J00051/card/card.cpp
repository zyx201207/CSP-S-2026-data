#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
long long n,m,a[N],cnt[N],ans[N],c[N];
bool st[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++) st[i]=0,c[i]=cnt[i];
		vector<long long> vec;
		long long sum=0;
		for(int j=i;j<=n;j++){
			if(c[a[j]]>1){
				if(st[a[j]]==0){
					sum+=1;
					st[a[j]]=1;
					c[a[j]]--;
				}
				else c[a[j]]--;
			}
			else{
				if(c[a[j]]==1){
					if(st[a[j]]==1){
						sum--;
						st[a[j]]=0;
						if(sum==0) vec.push_back(a[j]);
						c[a[j]]--;
					}
					else{
						if(sum==0) vec.push_back(a[j]);
						c[a[j]]--;
					}
				}
			}
		}
		for(int j=0;j<vec.size();j++) ans[vec[j]]++;
		cnt[a[i]]--;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
