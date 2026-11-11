#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int num=0,n,m,s,x,y;
	cin>>n>>m;
	vector<int> a;
	vector<int> mm;
	vector<int> ai;
	vector<int> aj;
	for(int i=0;i<n;i++){
		cin>>s;
		a.push_back(s);
		if(m==1){
			num=max(num,s);
		}
	}
	if(m==1){
		cout<<num<<endl;
		return 0;
	}
	vector<int> b=a;
	for(int i=0;i<a.size()-1;i++){
		for(int j=i+1;j<a.size();j++){
			mm.push_back(a[i]&a[j]);
			ai.push_back(i);
			aj.push_back(j);
		}
	}
	for(int i=0;i<mm.size();i++){
		if(num<mm[i]){
			num=mm[i];
			x=ai[i];
			y=aj[i];
		}
	}
	a.clear();
	for(int i=0;i<b.size();i++){
		if(i!=x&&i!=y){
			a.push_back(b[i]);
		}
	}
	mm.clear();
	ai.clear();
	aj.clear();
	for(int k=2;k<m;k++){
		for(int i=0;i<a.size();i++){
			mm.push_back(num&a[i]);
			ai.push_back(i);
		}
		for(int i=0;i<mm.size();i++){
			if(num<mm[i]){
				num=mm[i];
				x=ai[i];
			}
		}
		a.clear();
		for(int i=0;i<a.size();i++){
			if(i!=x){
				a.push_back(b[i]);
			}
		}
		mm.clear();
		ai.clear();
		aj.clear();
	}
	cout<<num<<endl;
	return 0;
}
