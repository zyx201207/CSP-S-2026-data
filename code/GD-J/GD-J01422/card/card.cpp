#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	vector<long long> a;
	bool b=true;
	long long mm[m+5]={0};
	a.push_back(-1);
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		a.push_back(x);
		if(a[i]<a[i-1]) b=false;
	}
	if(b==true){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout<<i<<' ';
			}
		}
		return 0;
	}
	int nn=n;
	while(n--){
		vector<long long> v;
		for(int i=nn-n;i<=nn;i++){
			b=false;
			long long pos;
			for(int j=0;j<v.size();j++){
				if(v[j]==a[i]){
					b=true;
					pos=j;
					break;
				}
			}
			if(!b){
				v.push_back(a[i]);
			}
			else{
				for(int j=0;j<v.size()-pos-1;j++)
					v.pop_back();
			}
		}
		for(int i=0;i<v.size();i++){
			mm[v[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mm[i]<<' ';
	}
	return 0;
}
