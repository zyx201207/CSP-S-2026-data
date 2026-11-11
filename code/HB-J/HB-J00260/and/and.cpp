#include<bits/stdc++.h>
using namespace std;
const int L=2e5+5;
int n,m,c;
bool s[L][40];
bool b[L];
void to2(int n,int x){
	for(int i=0;i<32;i++){
		if(n==0) break;
		s[x][i]=(n%2==0?false:true);
		n>>=1;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		 int d;
		 cin>>d;
		 to2(d,i);
		 b[i]=true;
	}
	for(int i=31;i>=0;i--){
		int f=0;
		for(int j=0;j<n;j++){
			if(b[j]==false) continue;
			if(s[j][i]==true) f++;
		}
		if(f>=m){
			c+=pow(2,i);
			for(int j=0;j<n;j++){
				if(b[j]==false) continue;
				if(s[j][i]==false) b[j]=false;
			}
		}
	}
	cout<<c;
	return 0;
}
