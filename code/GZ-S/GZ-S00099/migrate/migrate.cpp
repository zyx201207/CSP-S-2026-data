//GZ-S00099 王满霖 贵州省实验中学 
#include<bits/stdc++.h>
using namespace std;
int sb[2000010];
int main(){
	freopen("migrate.in","w",stdin);
	freopen("migrate.out","r",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=0;i<n;i++) cin>>sb[i];
		int a=sb[1]-sb[0];
		int sbsb=d/a;
		if(sb%2!=0) cout<<0;
		else{
			if(n%2!=0) cout<<(a^(n-(a*a))+a^(n-(a*a)-1));
			else cout<<(a^(n-((a+1)*a))+a^(n-((a+1)*a)-1));
		}
		cout<<"\n";
	}
	return 0; 
}
