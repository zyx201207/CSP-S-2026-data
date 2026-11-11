#include<bits/stdc++.h>
using namespace std;
int n,a[100005],lth,ans;
char c[100005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
			lth++;
		}
	}
	//cout<<s<<endl;
	for(int i=0;i<lth/2;i++){
	//	cout<<s[lth-i-1];
		if(s[i]!=s[lth-i-1])ans++;
	}
	cout<<ans;
    return 0;
}

