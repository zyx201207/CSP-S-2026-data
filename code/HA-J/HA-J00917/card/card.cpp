#include<bits/stdc++.h>
using namespace std;
long long n,m,b[300005];
char a[500005];
string s;
int find(string ss,char qa){
	for(int i=0;i<=ss.size()-1;i++){
		if(ss[i]==qa)
			return i;
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s=' ';
		for(int j=i;j<=n;j++){
			int l=s.size();
			if(find(s,a[j])==-1){
				s+=a[j];
			}else {
				s.erase(find(s,a[j]),l-find(s,a[j]));
				s+=a[j];
			}
		}
		for(int j=1;j<=s.size()-1;j++){
			b[s[j]-'0']++;
		}
		
	}
	for(int j=1;j<=m;j++){
		cout<<b[j]<<' ';
	}
	return 0;
}





