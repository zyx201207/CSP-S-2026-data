#include<bits/stdc++.h>

using namespace std;
const int N=2e5;
int n,a,ans;
char s;
string S;
void Main(){
	cin>>n;
	int m=1;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		for(int i=1;i<=a;i++){
			S[m]=s;
			m++; 
		}
	}
	m--;
	if((m-1)%2==1){
		m++;
	}
	for(int i=1;i<=(m-1)/2;i++){
		if(S[i]!=S[n-i+1])ans++;
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	Main();
	return 0;
}
