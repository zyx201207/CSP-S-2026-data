#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	string s="";
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			string str="";
			str=a[j];
		    if(s.find(str)!=-1){
		    	s.erase(s.find(str),s.size()-s.find(str));
			}
			s+=a[j];
		}
		for(int j=0;j<s.size();j++){
			b[s[j]]++;
		}
		s="";
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
