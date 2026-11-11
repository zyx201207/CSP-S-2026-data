//GZ-J00595 遵义市播州区保利小学 雷雨淳 
#include<bits/stdc++.h>
using namespace std;
string f(string a){
	string b;
	for(int i=0;i<a.size();i++){
		b=a[i]+b;
	}
	return b;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string m;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		string b;
		cin>>a>>b;
		while(a--){
			m=m+b;
		}
	}
	string c=f(m);
	if(c==m){
		cout<<0;
		return 0;
	}
	else{
		int w=0,q[26]={};
		for(int i=0;i<m.size();i++){
			if(m[i]!=c[i]){
				w++;
				q[c[i]-'a']++;
			}
		}
		sort(q+0,q+25+1);
		w=w-q[25];
		cout<<w;
		return 0;
	}
	
	return 0;
}
