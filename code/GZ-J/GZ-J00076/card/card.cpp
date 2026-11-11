//GZ-J00076 贵阳市第三中学 吴钰辉 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("crad.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long>a(n),ans(m,0),s(n,0);
	for(long long i=0;i<n;i++)cin>>a[i];
	vector<bool>f(m,0);
	for(long long k=0;k<n;k++){		
		for(long long i=k;i<n;i++){
			if(f[a[i]]==0){
				f[a[i]]=1;
				s[a[i]]=i;
			}
			else{
				for(long long j=s[a[i-1]];j<i;j++){
					f[a[j]]=0;
				}
				f[a[i]]=1;
			}
		if(f[a[i]]==1)ans[a[i]]++;
		}
	}
	for(long long i=0;i<m;i++)cout<<ans[a[i]]<<' ';
    return 0;
}
