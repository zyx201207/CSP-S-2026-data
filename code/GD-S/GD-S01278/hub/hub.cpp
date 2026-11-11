#include<bits/stdc++.h>
#define ll long long
using namespace std;

int calculate(){
	ll n,k;
	cin>>n>>k;
	
	vector<ll> array;
	
	for(ll i=0;i<n-1;i++){
		for(int j=0;j<2;j++){
			int temp;
			cin>>temp;
			array.push_back(temp);
		}
	}
	
	sort(array.begin(),array.end());
	
	int ans=1;
	for(size_t i=0;i<array.size()-1;i++){
		if(array[i+1]-array[i]>1)ans++;
	}
	
	return ans;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c,t;
	cin>>c>>t;
	
	while(t--){
		cout<<calculate()<<"\n";
	}
	
	return 0;
}
