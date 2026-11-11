#include<bits/stdc++.h>
using namespace std;
int ndzs;
long long asl[2005],anszs;
char csl[2005];
string pjhwc,pjhwczyl;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>ndzs;
	for(int i=1;i<=ndzs;i++){
		cin>>asl[i]>>csl[i];
		for(int j=1;j<=asl[i];j++){
			pjhwc[i]=csl[i];
		}
	}
	for(int i=ndzs;i>=1;i++){
		for(int j=1;j<=asl[i];j++){
			pjhwczyl[i]=csl[i];
		}
	}
	for(int i=1;i<=pjhwc.size()+1;i++){
		if(pjhwc[i]!=pjhwczyl[i]){
			anszs++;
		}
	}
	cout<<anszs/2;
	return 0;
}
