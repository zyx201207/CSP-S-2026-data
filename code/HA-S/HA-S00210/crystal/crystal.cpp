#include<bits/stdc++.h>
using namespace std;
long long n,m,s,l;
vector<int> ab(500010);//21
int main(){
	freopen("crystal.in","r",stdin);
	cin>>n>>m;
	bool q=1,p=1;
	for(int i=0;i<n;i++){
		cin>>ab[i];
		s+=ab[i];
	}
	sort(ab.begin(),ab.begin()+n);
	long long x=lower_bound(ab.begin(),ab.begin()+n,s/n)-ab.begin();
	long long ans=1;
	l=x-1;
	string w;
	for (int i=x-1;i>=0;i--){
		m-=(ab[x]-ab[i]);
		if(m<0){
			break;
		}
		ans++;
	}
	for (int i=x+1;i<n;i++){
		m-=i*(abs(ab[i]-ab[i-1]));
		if(m<0){
			break;
		}
		ans++;
	}
	cout<<ans;
	return 0;
	freopen("crystal.out","w",stdout);
}