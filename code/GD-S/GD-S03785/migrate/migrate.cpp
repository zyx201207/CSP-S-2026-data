#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,s[2000005],sum,g;
bool inf(){
	g=s[2]-s[1];
	for(int k=2;k<n;k++){
		if(s[k+1]-s[k]!=g) return false;
	}
	return true;
}
bool check(long long a,long long b){
	long long x=abs(s[a]-s[b]);
	if(x-d!=1){
		return false;
	}
	return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int v=1;v<=t;v++){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		if(inf()){
			if(g>=d){
				cout<<0;
			}else{
				for(int h=1;h<=n;h++){
					for(int w=1;w<=n;w++){
						if(s[w]+g+d==s[h]) sum++;
					}
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(check(i,j)){
						sum++;
					}
				}
			}
		}	
		cout<<sum<<"\n";
	}
	return 0;
}
