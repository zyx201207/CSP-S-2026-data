#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int s[N]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int q,w;
	cin>>q>>w;
	vector<int>v;
	vector<int>m;
	for(int i=1;i<=q;i++){
		cin>>a[i];
		v.push_back(a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(auto x:v){
		m.push_back(x);
	}
	for(int i=1;i<=q;i++){
		if(w==s[i]){
			for(int j=1;j<=i;j++){
				v[j]=0;
			}
		}
	}
	for(int i=1;i<=)
	for(int i=1;i<=w;i++){
		
	}
	return 0;
}
