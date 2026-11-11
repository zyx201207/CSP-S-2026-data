#include <bits/stdc++.h>
using namespace std;
long long n,i,j,k,y,m,len,s,l,r,ans;
pair<long long,char> x;
vector <pair<long long,char>> v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x.first>>x.second;
		len+=x.first;
		v.push_back(x);
	}
	if(len%2){
		k=len/2+1;
		for(i=0;i<n;i++){
			if(s+1<=k&&s+v[i].first>=k){
				//cout<<'*';
				x=v[i];
				v.erase(v.begin()+i);
				v.insert(v.begin()+i,{k-(s+1),x.second});
				v.insert(v.begin()+i+1,{s+x.first-k,x.second});
				break;
			}
			s+=v[i].first;
		}
	}
	else{
		k=len/2;
		for(i=0;i<n;i++){
			if(s+1<=k&&s+v[i].first>k){
				//cout<<'*';
				x=v[i];
				v.erase(v.begin()+i);
				v.insert(v.begin()+i,{k-s,x.second});
				v.insert(v.begin()+i+1,{s+x.first-k,x.second});
				break;
			}
			s+=v[i].first;
		}
	}
//	for(i=0;i<v.size();i++){
//		cout<<v[i].first<<' '<<v[i].second<<endl;
//	}
	
	l=0;
	r=v.size()-1;
	while(l<r){
		k=min(v[l].first,v[r].first);
		if(v[l].second!=v[r].second){
			ans+=k;
		}
		v[l].first-=k;
		v[r].first-=k;
		if(v[l].first==0){
			l++;
		}
		if(v[r].first==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}
