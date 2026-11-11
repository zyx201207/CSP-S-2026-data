#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n;
string c;
bool isok(string s){
	int len=s.size();
	int p=0;
	for(int i=1;i<=n/2;i++){
		for(int j=len;j>=n/2;j++){
			if(s[i]!=s[j]){
				p=1;
				break;
			}
		}
	}
	if(p==0)return 1;
	else return 0;
}

int main()
{
	string s;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1)cout<<0;
	else {
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s=s+c[i];
			}	
		}	
		if(isok(s))cout<<0;
	}
	
	return 0;
}  
