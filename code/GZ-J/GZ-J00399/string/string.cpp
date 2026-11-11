//GZ-J00399贵阳中天中学蒲科印 
#include<bits/stdc++.h>
using namespace std;
long long n;
long long sumn;
long long ans=0;
char a;
long long tot=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sumn>>a;
		tot+=sumn;
		for(int j=1;j<=sumn;j++){
			s+=a;
		}
	}
	long long l=0,r=tot-1;
	while(l<=r){
		if(s[l]!=s[r])ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
