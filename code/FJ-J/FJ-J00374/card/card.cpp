#include<bits/stdc++.h>
using namespace std;

bool cmp(const long long &a,const long long &b){
	return a>b;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.in","w",stdout);
	ios::sync_with_stdio(nullptr);
	cin.tie(false);
	int n,m;
	cin>>n>>m;
	vector<long long> a(n,0),b(10005,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		vector<long long> ddw(n-i,-1);
		long long e=0;
		
		for(int j=i;j<n;j++){
			long long d=0;
			
			for(;d<ddw.size();d++){
				if(ddw[d]==a[j]){
					break;
				}
			}
			
			ddw[d]=a[j];
			d++;
			
			for(;d<ddw.size();d++){
				ddw[d]=-1;
			}
			
		}
		for(int j=0;j<ddw.size();j++){
			if(ddw[j]==a[i]){
				b[a[i]]++;
				break;
			}
		}
	}
	sort(b.begin(),b.end(),cmp);
	vector<long long> dww(m,0);
	for(int i=0;i<m;i++){
		dww[i]=b[i];
	}
	sort(dww.begin(),dww.end());
	for(int i=0;i<dww.size();i++){
		if(i<dww.size()-1){
			cout<<dww[i]<<" ";
		}
		else{
			cout<<dww[i];
		}
	}
	return 0;
}
