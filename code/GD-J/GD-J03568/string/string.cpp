#include<bits/stdc++.h>
#define int long long
using namespace std;
struct innt{
	int x;
	char a;
}; 
int n;
vector<innt> v;
signed main(){
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		v.push_back({x,a});
	}
	int sum=0,l=0,r=n;
	while(l<r){
		if(v[l].x<v[r].x){
			if(v[l].a!=v[r].a){
				sum+=v[l].x;		
			}
			v[r].x-=v[l].x;
			l++;
		}
		else if(v[r].x<v[l].x){
			if(v[l].a!=v[r].a){
				sum+=v[r].x;	
			}
			v[l].x-=v[r].x;
			r--;
		}
		else if(v[l].x==v[r].x){
			if(v[l].a!=v[r].a){
				sum+=v[r].x;
			}
			l++;
			r--;
		}
	} 
	cout<<sum;
	return 0;
}
