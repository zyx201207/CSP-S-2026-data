#include<bits/stdc++.h>
using namespace std;
vector<long long> syf;
vector<long long> nn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		long long c;
		cin>>c;
		syf.push_back(c);
	} 
	int xx=syf.size();
	long long z;
	if(m==1){
	 z=syf[0];
		for(long long i=0;i<xx;i++){
			z=max(z,syf[i]);
		}
		cout<<z;
	}
	long long sz,ans;
	if(m==2){
		for(long long i=0;i<xx/2;i++){
			for(long long w=0;w<xx;w++){
				sz=syf[i]&syf[w];
				nn.push_back(sz);
			}
		}
		long long uu=nn.size();
				for(long long i=0;i<uu;i++){
					z=nn[0];
			z=max(z,nn[i]);
		}
		cout<<z;
		
	}
	long long dd=syf[0];
	if(m==n){
		for(long long i=0;i<xx;i++){
			dd&=syf[i];
		}
		cout<<dd;
	}
	return 0; 
	}

