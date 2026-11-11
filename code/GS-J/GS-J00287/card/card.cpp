#include<bits/stdc++.h>
using namespace std;
long long a,n,ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>n;
	deque<long long>x;
	deque<long long>y;
	deque<long long>z;
	vector<long long>v(n+1,0);
	for(int i=0;i<a;i++){
		long long s;
		cin>>s;
		z.push_back(s);
	}
	while(!z.empty()){
		y=z;
		z.pop_front();
		vector<long long>e(n+1,-1);
		vector<bool>u(n+1,0);
		while(!y.empty()){
			long long m=y.front();
			y.pop_front();
				if(!x.empty()){
				for(int j=0;j<x.size();j++){
					long long p=x.size();
					if(x[j]==m){
						for(int q=j+1;q<p;q++){
							x.pop_back();
						}
					}else{
						x.push_back(m);
					}
				}
			}else{
				x.push_back(m);
			}
	}
	for(int g=0;g<x.size();g++){
		u[x[g]]=1;
	}
		for(int k=0;k<x.size();k++){
			if(e[x[k]]==-1&&u[x[k]]==1){
				v[x[k]]++;
				e[x[k]]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
