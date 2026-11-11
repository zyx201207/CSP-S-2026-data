#include<bits/stdc++.h>
using namespace std;
int n,a[5*114514],m,ds[3*114514];
int fnd(int k,int l,vector<int>a){
	//cerr<<endl;
//	cerr<<k<<" "<<l;
	//f//or(int i=0;i<a.size();i++)cerr<<a[i]<<" ";
	//		cerr<<endl;
	for(int i=l-1;i<a.size();i++){
		if(a[i]==k){
		//	cerr<<"33333\n";
			return i;
		}
	}
	return -1;
}
void solve(int k){
	vector<int>v;
	for(int i=k;i<=n;i++){
		int tmp=fnd(a[i],k,v);
		if(tmp==-1){
		//	cerr<<"2222"<<endl;
			v.push_back(a[i]);
			//for(int i=0;i<v.size();i++)cerr<<v[i]<<" ";
			//cerr<<endl;
		}else{
			for(int i=v.size()-1;i>=tmp;i--){
				v.erase(v.end());
		//		cerr<<"1111"<<endl;
			}
			//v.push_back(a[i]);
		//	for(int i=0;i<v.size();i++)cerr<<v[i]<<" ";
		//	//cerr<<endl;
		}
		
	}
	cerr<<endl;
	for(int i=0;i<v.size();i++){
		ds[v[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ds[i]<<' ';
	}
	return 0;
}

