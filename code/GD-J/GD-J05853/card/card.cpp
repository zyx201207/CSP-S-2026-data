#include<bits/stdc++.h>
using namespace std;
long long a[2000005],t[2000005];
bool fll[2000005] ,d[2000005];
vector<long long> v,c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=1;
	while(cnt<=n){
		for(long long i=cnt;i<=n;i++){
			if(fll[a[i]]==1) continue;
			if(!v.empty()){
				bool fl=0;
				for(long long j=0;j<v.size();j++){
					if(v[j]==a[i]){
						fl=1;
					}
					if(fl==1){
						v[j]=0;
						fll[v[j]]=1;
					}
				}
			}
			v.push_back(a[i]);
		}
		for(long long i=1;i<=m;i++){
			fll[i]=0;
		}
		for(long long i=0;i<v.size();i++){
			t[v[i]]++;
		}
		cnt++;
		v=c;
	}
	for(long long i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
