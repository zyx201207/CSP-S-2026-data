#include<bits/stdc++.h>
using namespace std;
int a,b[200001];
string d; 
char c[200001];
int y=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i]>>c[i];
		for(int j=0;j<b[i];j++){
			d+=c[i];
		}
	}
	for(int i=0;i<d.size()/2;i++){
		if(d[i]!=d[d.size()-i-1]){
			y++;
		}
	}
	cout<<y;
	return 0;
}
