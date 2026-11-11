#include<bits/stdc++.h>
using namespace std;
/*bool check(string s){
	string s1=s;
	reverse(s.begin(),s.end());
	return s==s1;
}*/
bool b=1;
long long a[200005],n,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=2;i<=n;i++)if(c[i]!=c[i-1])b=0;
	if(b==1){
		cout<<"0"<<endl;
		return 0;
	}else if(n==2){
		cout<<min(a[1],a[2]);
		return 0;
	}
	//cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
