#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
map <long long,long long> b;
string s;
struct inf{
	int a,b;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cout<<s;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map <int,inf> mp={};
		for(int j=i;j<=n;j++){
			if(mp[a[j]].b!=0){
//				cout<<mp[a[j]].b<<"  "<<j<<"\n";
				for(int k=mp[a[j]].b;k<j;k++){
					if(mp[a[k]].a!=1){
						continue;
					}
					b[a[k]]--;
					mp[a[k]].b=0;
					mp[a[k]].a=0;
				}
			}
			b[a[j]]++;
			mp[a[j]].a=1;
			mp[a[j]].b=j;
		}
	}
	for(auto p:b){
		cout<<p.second<<" ";
	}
	return 0;
} 
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/

