#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<int>v;
vector<int>v_;
long long h;
long long p;
long long u;
long long s1;
bool qwq(int t){
	for(int i=0;i<s1;i++){
		if(v_[i]==t){
			p=i;
			return false;
		}
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>h;
		v.push_back(h);
	}
	long long sum=0;
	s1=v_.size();
	for(int o=1;o<=m;o++){
		sum=0;
		for(int i=0;i<n;i++){
			v_.clear();
			for(int j=0;j<n;j++){
				if(j<i) continue;
				if(qwq(v[j])){
					v_.push_back(v[j]);
					s1=v_.size();
				}
				else{
					for(int e=p;e<n;e++){
						v_.pop_back();
					}
					v_.push_back(v[j]);
					s1=v_.size();
				}
			}
			for(int w=0;w<s1;w++){
				if(v[w]==o) sum++;	
			}
		}
		cout<<sum<<" ";
	}
	return 0;
}
