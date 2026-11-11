#include<bits/stdc++.h>
using namespace std;
int n;
string st;
int hw(string s){
	int sz=s.size();
	int df=0;
	for(int i=0;i<sz/2;i++){
		if(s[i]!=s[sz-i-1]){
			df++;
		}
	}
	return df;
}
struct stg{
	int nb;
	char k;
}a[200005];
void hw1(string s){
	int sz=s.size();
	long long df=0;
	for(int i=0;i<sz/2;i++){
		if(s[i]!=s[sz-i-1]){
			df+=min(a[i+1].nb,a[sz-i].nb);
		}
	}
	cout<<df;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=2000){
		for(int i=1;i<=n;i++){
			int x;
			char k;
			cin>>x>>k;
			for(int j=1;j<=x;j++){
				st+=k;
			}
		}
		cout<<hw(st);
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
		cin>>a[i].nb>>a[i].k;
		st+=a[i].k;
	}
	hw1(st);
	return 0;
	}
}

