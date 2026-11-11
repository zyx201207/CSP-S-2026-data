//GZ-J00551     南白初级中学-王子杰   
#include <bits/stdc++.h>
using namespace std;
long long n,m,aaa;
long long ans[300005],w[300005],s[300005];
string a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>aaa;
		s[aaa]++;
		if(w[aaa]==0) w[aaa]=i;
		else{
			for(long long j=1;j<=m;j++){
				if(w[j]>w[aaa]&&w[j]<i){
					s[j]--;
				}
				w[aaa]=0;
				s[aaa]-=2;
			}
		}
		for(long long j=1;j<=m;j++){
			if(s[j]>0) ans[j]+=s[j];
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

