#include<bits/stdc++.h>
using namespace std;
long long n,m,x,ans;
vector<long long> a,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a.push_back(x);
	}	
	for(int i=31;i>=0;i--){
		int l=a.size();
		long long s=(1<<i);
		for(int i=0;i<l;i++){
			if((a[i]&s)==s){
				b.push_back(a[i]);
			}
		}	
		int l2=b.size();
		if(l2>=m){
			a.clear();
			for(int i=0;i<l2;i++){
				a.push_back(b[i]);
			}	
			ans+=s;
		}	
		b.clear();
	}
	cout<<ans;
	return 0;
}


