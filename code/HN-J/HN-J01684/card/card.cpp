#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int l=1;l<=n;l++){
		string s="";
		for(int i=l;i<=n;i++){
			int f=1;
			for(int j=0;j<s.size();j++){
				if(s[j]==char(i)){
					for(int d=j;d<s.size();d++){
						s[i]=' ';
					} 
				}
			} 
			s+=char(i);
		}
		for(int i=0;i<s.size();i++){
			b[int(s[i])]++;
		}		
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}	
	return 0;
}
