#include<bits/stdc++.h>
using namespace std;
struct str{
	int num;
	string s;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	str a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].s;
	}
	string b;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].num;j++){
			b+=a[i].s;
		}
	}
	int u=0;
	int v=b.size();
	if(v%2==0){
		string c,d;
		for(int i=0;i<v;i++){
			if(i<v/2){
				c+=b[i];
			}else{
				d+=b[i];
			}
		}
		
		v=c.size();
		for(int i=0;i<v;i++){
			if(c[i]!=d[d.size()-1-i]){
				d[d.size()-1-i]=c[i];
				u++;
			}
		}
	}else{
		string c,d;
		for(int i=0;i<v;i++){
			if(i<(v+1)/2){
				c+=b[i];
			}else if(i>(v+1)/2){
				d+=b[i];
			}
		}
		v=c.size();
		for(int i=0;i<v;i++){
			if(c[i]!=d[d.size()-1-i]){
				d[d.size()-1-i]=c[i];
				u++;
			}
		}
	}
	cout<<u;
	return 0;
}
