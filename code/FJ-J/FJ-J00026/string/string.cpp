#include<bits/stdc++.h>
using namespace std;
long long s[200001];
char a[200001];
long long ans;
int n;
int main(){
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin>>s[i]>>a[i];
	}
	long long i=1,j=n;
	while(i<j){
		if(a[i]==a[j]){
			int ma = min(s[i],s[j]);
			s[i]-=ma;
			s[j]-=ma;
			if(s[i]==0) i++;
			if(s[j]==0) j--;
		}
		else{
			int ma = min(s[i],s[j]);
			s[i]-=ma;
			s[j]-=ma;
			if(s[i]==0) i++;
			if(s[j]==0) j--;
			ans+=ma;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
