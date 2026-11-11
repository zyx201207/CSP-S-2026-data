#include<bits/stdc++.h> 
using namespace std;

int n,m;
char a[1000000];
string s;
int b[1000000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int pos=0;
	while(pos<n){
		pos++;
		s="";
		for(int i=pos;i<=n;i++){
			for(int j=0;j<=s.size()-1;j++){
				if(a[i]==char(s[j])) s.erase(j,s.size()-j);
				s+=a[i];
			}
		}
		for(int i=0;i<=s.size()-1;i++){
			b[int(s[i])-48]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
