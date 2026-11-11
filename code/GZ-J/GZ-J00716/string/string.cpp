//GZ-J00716 北京师范大学贵阳附属中学 邹骐骏;
#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a="";
	int ans=0;
	int n;
	cin >>n;
	for(int i=0;i<n;i++){
		int m=0;
		string o="";
		cin>>m>>o;
		for(int i=0;i<m;i++){
			a+=o;
		}
	}
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-1-i]){
			ans++;
		}
	}
	cout <<ans;
}
