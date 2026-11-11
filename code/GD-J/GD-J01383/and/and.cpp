#include<bits/stdc++.h> 
using namespace std;
string s[200005],s1[200005],lz;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		while(a>1){
			s1[i]+=a%2+'0';
			a/=2;		
		}
		s1[i]+='1';
		for(int j=0;j<s1[i].size();j++){
			s[i][j]=s1[i][s1[i].size()-1-j];
		}
		if(s[i]>=lz){
			lz=s[i];
		}
	}

		cout<<lz;

	return 0;
}

