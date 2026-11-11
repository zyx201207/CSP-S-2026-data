#include<bits/stdc++.h>
using namespace std;
int n,a[200010],q;
char c;
string s,f1,f2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		for(int j=0;j<a[i];j++){
			s+=c;
		}
	}
	int m=s.size();
	int k=m;
	for(int i=0;i<m/2;i++){
		f1+=s[i];
		f2+=s[--k];
	}
	for(int i=0;i<m/2;i++){
		if(f1[i]!=f2[i]){
			q++;
		}
	}
	cout<<q;
	return 0;
}
