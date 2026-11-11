#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char c;
};
int n;
long long ans;
vector<node>v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		if(v.empty()||v.back().c!=c)v.push_back((node){a,c});
		else v.back().num+=a;
	}
	int l=0;
	int r=v.size()-1;
	while(l!=r&&l<v.size()&&r>=0){
		long long mina=min(v[l].num,v[r].num);
		v[l].num-=mina;
		v[r].num-=mina;
		if(!v[l].num&&!v[r].num){
			if(v[l].c!=v[r].c)ans+=mina;
			l++;
			r--;
		}else if(v[l].num){
			if(v[l].c!=v[r].c)ans+=mina;
			r--;
		}else{
			if(v[l].c!=v[r].c)ans+=mina;
			l++;
		}
	}
	cout<<ans;
}
