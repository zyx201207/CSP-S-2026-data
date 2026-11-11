#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		string s="";
		for(int j=i;j<=n;j++){
			string t="";
			for(int k=0;k<s.size();k++){
				if(s[k]==char('0'+a[j]))break;
				else t+=s[k];
			}
			s=t;
			s+=char('0'+a[j]);
		}
		for(int i=0;i<s.size();i++){
			t[int(s[i]-'0')]++;
		}
		//cout<<s<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
