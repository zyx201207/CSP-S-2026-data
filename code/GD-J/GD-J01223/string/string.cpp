# include<bits/stdc++.h>
# define int long long
using namespace std;
pair<int,char>A[1000001];
vector<pair<int,char>>a,b;
int n,L,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>A[i].first>>A[i].second,L+=A[i].first;
	if(L%2==1){
		int v=(L+1)/2,sum=0;
		for(int i=1;i<=n;i++){
			sum+=A[i].first;
			if(sum>=v){A[i].first--;break;}
		}
		L--;
	}
	int v=L/2,sum=0;
	for(int i=1;i<=n;i++){
		if(sum<v&&sum+A[i].first>=v){
			a.push_back({v-sum,A[i].second});
			b.push_back({A[i].first-(v-sum),A[i].second});
		}
		else if(sum<v)a.push_back(A[i]);
		else b.push_back(A[i]);
		sum+=A[i].first;
	}	
	for(int i=0;i<(int)a.size()-1-i;i++)swap(a[i],a[(int)a.size()-1-i]);
	while(a.size()&&a.back().first==0)a.pop_back();
	while(b.size()&&b.back().first==0)b.pop_back();
	while(a.size()&&b.size()){
		int v=min(a.back().first,b.back().first);
		if(a.back().second!=b.back().second)ans+=v;
		a.back().first-=v,b.back().first-=v;
		while(a.size()&&a.back().first==0)a.pop_back();
		while(b.size()&&b.back().first==0)b.pop_back();
	}
	cout<<ans;
}
