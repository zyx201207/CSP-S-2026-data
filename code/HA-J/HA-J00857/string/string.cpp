#include <bits/stdc++.h>
using namespace std;
long long ans=0;
vector<pair<long long,long long> > v1,v2;
vector <long long> pos; 
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len>>c;
		v1.push_back(make_pair(len,(long long)(c-97)));
		v2.push_back(make_pair(len,(long long)(c-97)));
	}
	reverse(v2.begin(),v2.end());
	for(int i=1;i<v1.size();i++){
		v1[i].first=v1[i-1].first+v1[i].first;
		//cout<<v1[i].first<<" ";
	}
	//cout<<endl;
	for(int i=1;i<v2.size();i++){
	    v2[i].first=v2[i-1].first+v2[i].first;
	    //cout<<v2[i].first<<" ";
	}
	//cout<<endl;
	for(int i=0;i<n;i++){
		pos.push_back(v1[i].first);
		pos.push_back(v2[i].first);
	}
	sort(pos.begin(),pos.end());
	long long l=0,r=0,zz1=0,zz2=0;
	for(int i=0;i<pos.size();i++){
		//cout<<pos[i]<<" ";
		l=r;
		r=pos[i];
		if(v1[zz1].first<r){
			zz1++;
		}
		if(v2[zz2].first<r){
			zz2++;
		}
		if(v1[zz1].second!=v2[zz2].second){
			//cout<<"("<<zz1<<","<<zz2<<")";
			ans+=r-l;
		}
	}
	cout<<ans/2;
	return 0;
}
