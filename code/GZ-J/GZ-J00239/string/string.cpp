//GZ-J00239 ñûĞÅÖ² 
#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int b,n;
	string a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b>>a;
		for(int j=1;j<=b;j++)s+=a;
	}
	long long ans=0;
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
//		if(i>j)break;
		if(s[i]!=s[j])ans++;
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
