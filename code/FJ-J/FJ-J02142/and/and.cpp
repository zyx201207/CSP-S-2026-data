#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200009],ans;
vector<long long>v[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		long long sum=a[i];
		int j=0;
		while(a[i]){
			if(a[i]&1){
				v[j].push_back(sum);
			}a[i]>>=1;
			j++;
		}
	}for(int i=30;i>=0;i--){
		int len=v[i].size();
		if(len>=m){
			sort(v[i].begin(),v[i].end());
			m--;
			ans=v[i][len-1];
//			cout<<v[i][len-1]<<" ";
			for(int j=len-2;j>=0&&m;j--){
				ans&=v[i][j];
//				cout<<v[i][j]<<" ";
				m--;
			}break;
		}
	}printf("%lld",ans);
	return 0;
} 
