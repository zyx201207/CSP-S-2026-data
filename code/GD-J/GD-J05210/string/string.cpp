#include<bits/stdc++.h>
using namespace std;
long long n,a;
string s;
char c;
bool hw(string x){
	string d=x;
	reverse(x.begin(),x.end());
	if (d==x) return 0;
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>c;
		for (long long j=1;j<=a;j++){
			s+=c;
		}
	}
	int l=0,r=s.size()-1;
	while (hw(s)){
		s[r]=s[l];
		l++;
		r--;
	}
	cout<<l;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
