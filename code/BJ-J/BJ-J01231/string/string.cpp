#include<bits/stdc++.h>
using namespace std;
string a;
char w;
long long e;
int n,q;
long long ans;
int main(){
	freopen("string.in","r"，stdin);
	freopen("string.out","w"，stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	while(n--){
		cin>>q;
		cin>>w;
		for(int i=0;i<q;i++){
			a+=w;
		}
	}
	e=(a.size());
	for(int i=0;i<e/2;i++){
		if(a[i]!=a[e-i-1])ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
