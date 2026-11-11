#include <bits/stdc++.h>
using namespace std;
const int N=1e8+10;
long long n,m,a[N],js[N];
vector <int> vec;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vec.empty()){
				vec.push_back(a[j]);
			}else{
				for(int x=0;x<vec.size();x++){
					if(vec[x]==a[j]){
						while(vec.size()>x) vec.erase(vec.begin()+x);
					}
				}
				vec.push_back(a[j]);
			}
		}
		for(int i=0;i<vec.size();i++){
			js[vec[i]]++;
		}
		vec.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<js[i]<<" ";
	}
	return 0;
}
