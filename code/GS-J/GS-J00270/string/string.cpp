#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+4;
int a[N];
string s[N],s1[N];
int L;
string S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>L;
	for(int i=1;i<=L;i++){
		cin>>a[i];
		cin>>s[i];
	}
	for(int i=1;i<=L;i++){
		for(int j=1;j<=a[i];j++){
			s1[i]+=s[i];
		}
	}
	for(int i=1;i<=L;i++){
		S+=s1[i];
	}
	int zhizhen=S.size();
	int cnt;
	if(S.size()%2==0){
		cnt=S.size()/2;
	}else{
		cnt=S.size()/2+1;
	}
	int sum=0;
	for(int i=0;i<=cnt;i++){
		if(S[i]!=S[zhizhen]){
			sum++;
		}
		zhizhen--;
	}
	cout<<sum;
	return 0;
}
