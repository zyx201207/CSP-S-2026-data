#include<bits/stdc++.h>
using namespace std;
string s;
char c[200005];
long long n,a[200005],sum,ans,f;
vector<pair<long long,char>> v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		cin>>a[i]>>c[i];
		if(i>1){
			if(c[i]!=c[i-1]){
//				cout<<c[i]-c[i-1]<<endl;
				f=1;
			}
		}
		v.push_back({a[i],c[i]});
//		cout<<f<<endl;
	}
	if(f==0){
//		cout<<"!!!"<<endl;
		cout<<0;
		return 0;
	}
//	if(sum<=200005){
//		s+=" ";
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=a[i];j++){
//				s+=c[i];
//			}
//		}
//		for(int i=1;i<=(sum+1)/2;i++){
//			if(s[i]!=s[sum-i+1]) ans++;
//		}
//		cout<<ans<<endl;
//		return 0;
//	}
	while(v.size()>1){
//		cout<<"!!!"<<endl;
		if(v[0].second==v[v.size()-1].second){
//			cout<<1<<" ";
			if(v[0].first==v[v.size()-1].first){
//				cout<<1<<" ";
				v.pop_back();
				v.erase(v.begin());
			}else if(v[0].first>v[v.size()-1].first){
//				cout<<2<<" ";
				v[0].first-=v[v.size()-1].first;
				v.pop_back();
			}else{
//				cout<<3<<" ";
				v[v.size()-1].first-=v[0].first;
				v.erase(v.begin());
			}
		}else{
//			cout<<2<<" ";
			if(v[0].first==v[v.size()-1].first){
//				cout<<1<<" ";
				ans+=v[0].first;
				v.pop_back();
				v.erase(v.begin());
			}else if(v[0].first>v[v.size()-1].first){
//				cout<<2<<" ";
				ans+=v[v.size()-1].first;
				v[0].first-=v[v.size()-1].first;
				v.pop_back();
			}else{
//				cout<<3<<" ";
				ans+=v[0].first;
				v[v.size()-1].first-=v[0].first;
				v.erase(v.begin());
			}
		}
//		cout<<endl;
	}
	cout<<ans;
	
	return 0;
}
