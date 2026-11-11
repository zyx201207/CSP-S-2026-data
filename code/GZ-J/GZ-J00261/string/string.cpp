//GZ-J00261 遵义市第十一中学 夏琮凯  02
#include <bits/stdc++.h>
using namespace std;
int n;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;string c;
		cin>>a>>c;
		while (a--) s+=c;
	}
	long long r=s.size()-1;
	long long ans=0;
	for(long long l=0;l<r/2;l++){
		r=s.size()-1-l;
		if(s[l]!=s[r]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

