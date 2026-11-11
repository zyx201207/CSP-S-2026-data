//GZ-J00652 ует╙Ог 
#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],jg,zc;
string c[200001],S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++){
			S+=c[i];
		}
	}if(S.size()%2==0){
		for(long long i=0;i<=S.size()/2-1;i++)
		if(S[i]!=S[S.size()-i-1])jg++;
	}else{
		for(long long i=0;i<=S.size()/2;i++)
		if(S[i]!=S[S.size()-i-1])jg++;
	}
	cout<<jg<<endl;
	return 0;
}
