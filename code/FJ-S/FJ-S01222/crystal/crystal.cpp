#include <bits/stdc++.h> 
using namespace std;
vector <long long> v;
const int N=5e5+78;
long long n,m,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long op;
		cin>>op;
		v.push_back(op);
	}
	sort(v.begin(),v.end());
	long long k=v.size(),cha;
	for(long long i=1;i<k;i++){
		cha=v[i]-v[i-1];
		if(cha!=0){
			if(m>=(long long)cha*ans){
				m-=cha*ans;
				v[i-1]=v[i];
				ans++;
			}
			else{
				break;
			}
		}
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
