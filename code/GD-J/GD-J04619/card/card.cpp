#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
string s,s1;
int n,m,num=1,cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	s=' '+s;
	s1=' ';
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			char l='0'+a[j];
			char lx='0'+a[j+1];
			s+=l;
			int loc=s.find(lx);
			if(loc>0){
				for(int i=1;i<loc;i++){
					s1+=s[i];
				}
				s=s1;
				s1=' ';
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<s.size();j++){
				int o=s[i]-'1'+1;
				b[o]++;
			}
		}
		s=' ';
		s1=' ';
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;

} 
