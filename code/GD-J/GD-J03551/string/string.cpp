#include<bits/stdc++.h>//40
using namespace std;
int n;//分成几个子段
unsigned long long m;//字段元素个数 
char c;//字段元素 

string ansstring;
unsigned long long ans;

unsigned long long check(string s2){
	for(unsigned long long i=0;i*2<=s2.length();i++){
		if(s2[i]!=s2[s2.length()-1-i])ans++;
	}
	return ans;
} 

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		string s(m,c);
		ansstring+=s;
	}
	check(ansstring);
	cout<<ans;
	return 0;
}
