#include<bits/stdc++.h>
using namespace std;
string s;
const int N=2*1e5+5;
long long cnt;
int a[N],n,m;
char d[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>d[i];
		int j=a[i];
		while(j--){
			s+=d[i];
		}
	}
	if(n<=2){
		if(n==1){
			cout<<0;
		}
		else{
			int g=min(a[1],a[0]);
			cout<<g;
		}
	}
	else{
		int j=s.length();
		for(int i=0;i<j/2;i++){
			if(s[i]==s[j-i-1]) continue;
			else{
				cnt++;
			}
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
