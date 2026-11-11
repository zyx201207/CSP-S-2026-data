#include<bits/stdc++.h>
using namespace std;
long long shu[200005];
char zi[200005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	string s="",ss="";
	long long n,cnt=0,zo=0,z1=0,z2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>shu[i]>>zi[i];
		zo+=shu[i];
	}
	zo/=2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=shu[i];j++){
			if(zo>z1){
				s+=zi[i];
				z1++;
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=shu[i];j++){
			if(zo>z2){
				ss+=zi[i];
				z2++;
			}
		}
	}
	int len=s.size();
	for(int i=0;i<=len-1;i++){
		if(s[i]!=ss[i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
