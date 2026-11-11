#include<bits/stdc++.h>
using namespace std;
long long int n,a[200010],ans;
char b[200010];
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		ans+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	int i=1,j=ans;
	ans=0;
	while(i<=j){
		if(s[i]!=s[j]){
			ans++;
		}
		i++;
		j--;
	}
	cout<<ans;
	return 0;
}

