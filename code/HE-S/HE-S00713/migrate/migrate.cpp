#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,t,k;
	cin>>c>>t>>k;
	int num=0;
	int s[t];
	for(int i=0;i<t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=0;j<n;j++){
		int s;
		num=num+s;
		}
		s[i]=num;
		num=0;
	}
	for(int i=1;i<=t;i++){
		cout<<(s[i]-k)/t;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
