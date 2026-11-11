#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
vector<int>b,d;
char c[200010];
int p(int x){
	int ans=1;
	for(int i=1;i<=x;i++){
		ans*=2;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b.push_back(a[i]);
	}
	for(int i=29;i>=0;i--){
		d.clear();
		int tmp=0;
		for(int j=0;j<b.size();j++){
			if(b[j]&p(i)){
				tmp++;
				d.push_back(b[j]);
			}
		}
		if(tmp>=m){
			ans+=p(i);
			b.clear();
			b=d;
		}
	}
	cout<<ans;
	return 0;
} 
