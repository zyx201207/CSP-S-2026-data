#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[300005];
vector<long long> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int num=1;num<=n;num++){
		v.clear();
//		cout<<num<<":"<<endl;
		for(int i=num;i<=n;i++){
			int f=-1;
			for(int j=0;j<v.size();j++){
				if(v[j]==a[i]){
					f=j;
					break;
				}
			}
			if(f==-1) v.push_back(a[i]);
			else{
				while(1){
					if(v.back()==a[i]) break;
					v.pop_back();
				}
			}
//			for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
//			cout<<endl;
		}
		for(int i=0;i<v.size();i++){
			sum[v[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	
	return 0;
}
