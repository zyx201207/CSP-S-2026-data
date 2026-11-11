//GZ-J00197   遵义市第四中学	代铭轩 
#include <bits/stdc++.h>
using namespace std;
const int maxn=500110,maxm=300110;
long long a[maxn],b[maxn],tong[maxn],q[maxn];
vector<long long> _now;
int n,m,num=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>b[i];
		a[i]=b[i];
	}
	for(int ii=1;ii<=n;++ii){
		for(int jj=ii;jj<=n;++jj){
			long long x=a[jj];
				for(int i=0;i<_now.size();++i){
					if(_now[i]==x){
						for(int j=1;j<=n-i+1;j++){
							if(!_now.empty()){
								_now.pop_back();
							}
						}
					}
				}
				_now.push_back(x);
				for(int i=0;i<_now.size();++i){
					cout<<_now[i]<<" ";
				}
				cout<<endl;
		}
		bool b[maxn]={0};
		for(int i=1;i<=n;++i){
			if(b[a[i]]==0){
				b[a[i]]=1;
				tong[a[i]]++;
			}
		}
		num++;
		fill(a,a+1+n,0);
		for(int i=1;i<=n;++i){
			a[i]=b[i];
		}
	}
	for(int i=1;i<=m;++i){
		if(tong[i]!=0){
			cout<<tong[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

