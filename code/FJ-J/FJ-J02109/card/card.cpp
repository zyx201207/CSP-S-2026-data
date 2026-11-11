#include<bits/stdc++.h>
using namespace std;
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a;
	vector<map<int,bool>> mp(n);
	for(int i=1;i<=n;i++){
		int ip;cin>>ip;a.push_back(ip);
	}
	if(n>5000&&m>3000){
		vector<int> qc;
		qc.push_back(0);
		int zz=0;
		for(int i=1;i<=m;i++){
			int cyr=0;
			while(zz<n&&a[zz]==i){
				zz++;
				cyr++;
			}
			qc.push_back(cyr);
		}
		for(int i=1;i<=m;i++){
			int sum;
			sum=i*qc[i];
			cout<<sum<<" "; 
		}
	}
	else{
		for(int i=0;i<n;i++){
		vector<int> b;
		for(int j=i;j<n;j++){
			bool flag=0;
			for(int k=0;k<b.size();k++){
				if(k==a[j]){
					flag=1;
				}
				if(flag){
					b[k]=0;
				}
			}
			b.push_back(a[j]);
		}
		for(int j=0;j<b.size();j++){
			mp[i][b[j]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		int sum=0;
		for(int j=0;j<n;j++){
			if(mp[j].count(i)){
				sum++;
			}
		}
		cout<<sum<<" ";
	}
	}
	return 0;
}
