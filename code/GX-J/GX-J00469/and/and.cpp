#include<bits/stdc++.h>
using namespace std;
int and(int p,int q){
	string b,c;
	while(p!=0){
		if(p%2==0){
			b.push_back('0');
			p/=2;
		}
		else
			b.push_back('1');
	}
	while(q!=0){
		if(q%2==0){
			c.push_back('0');
			q/=2;
		}
		else
		c.push_back('1');
	}
	if(b.size()!=c.size()){
		if(b.size()>c.size()){
			for(int i=0;i<b.size()-c.size();i++){
				c.push_back('0');
			}
		}
		else{
			for(int i=0;i<c.size()-b.size();i++){
				b.push_back('0');
			}
		}
	}
	reverse(b.begin(),b.end());
	reverse(c.begin(),c.end());
	string d;
	for(int i=0;i<b.size();i++){
		if(b[i]==c[i]){
			d.push_back('1');
		}
		else{
			d.push_back('0');
		}
	}
	reverse(d.begin(),d.end());
	int bl=0,xt=1,jy=0;
	for(int i=0;i<d.size();i++){
		while(jy==i){
			xt*=2;
			jy++;
		}
		bl+=xt;
	}
	return bl;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		a.push_back(t);
	}
	int max=-1,k;
	if(m==2){
		for(int i=1;i<a.size();i++){
			for(int j=0;j<i;j++){
				int o,l;
				o=a[i];
				l=a[j];
				k=and(o,l);
				if(k>max){
					max=k;
				}
			}
		}
		cout<<max;
	}
	else{
		cout<<a[a.size()-1];	
	}
	return 0;
}
