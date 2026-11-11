#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
int n,m;
vector<int> a;
vector<int> dk;
ll ans[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==1){
		cout<<n<<'\n';
		return 0;
	}
	for(int x=1;x<=n;x++){
		for(int i=x;i<=n;i++){
			if(dk[dk.size()-1]==a[i]){
				for(int k=i;k<dk.size();k++) dk[k]=0;
			}
			dk.push_back(a[i]);
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<dk.size();j++){
				if(dk[j]==i) ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
} 
