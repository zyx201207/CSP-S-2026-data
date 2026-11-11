//ÌÆÎÄ²©  GZ-J00100
#include<bits/stdc++.h>
using namespace std;
long long ans,k;
string zj;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	long long n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		char s;
		cin>>m>>s;
		for(long long j=k;j<=k+m;j++){
			zj[j]=s;
		}	
		k+=m;
	}
	long long l=0,j=k;
	while(l<j){
		if(zj[l]!=zj[j]) ans++;
		l++;j--;
	}
	cout<<ans; 
} 
