#include<bits/stdc++.h> 
using namespace std;
string s;
const int maxn=1e5+10;
int a[2*maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		int x=a[i];
		char y;
		cin >> y;
		while(x--){
			s+=y; 
		}
	}
	long long sum=0;
	for(int i = 0,j=s.size()-1;i < j;i++,j--){
		if(s[i]!=s[j])sum++; 
	}
	cout << sum;
	return 0;
}
