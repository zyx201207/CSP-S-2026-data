#include <bits/stdc++.h>
using namespace std;
long long int n,x,t,p,maxl,ans,s1f,s1s,s2f,s2s,m,k,v;
map <long long int,int> a;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	p=m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
		if(a[x]>maxl) maxl=a[x];
	}
	for(auto i=a.begin();i!=a.end();i++){
		ans=(*i).second;
		k=(*i).first;
		s1s=0;
		m=p;
		v=0;
		for(auto it=i;it!=a.end();it++){
			v=0;
			s1s+=(*it).second;
			s1f=(*it).first;
			it++;
			if(it==a.end()) break;
			s2s=(*it).second;
			s2f=(*it).first;
			if((s2f-s1f)*s1s>m){
				for(auto j=i;j!=a.begin();j--){
					j--;
					if(m>(s1f-(*j).first)*(*j).second){
						m-=(s1f-(*j).first)*(*j).second;
						v+=(*j).second;
					}
					else{
						v+=m/(s1f-(*j).first);
						break;
					}
					j++;
				}
				ans=max(ans+v,m/(s2f-s1f)+s2s);
				break;
			}
			else{
				m-=(s2f-s1f)*s1s;
				ans+=s2s;
			}
			it--;
		}
		maxl=max(maxl,ans);
	}
	cout<<maxl;
	return 0;
}
