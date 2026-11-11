#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in.txt","r",stdin);
	freopen("string.out.txt","w",stdout);
	string s;
	int n;
	long long cnt=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		int m;
		string k;
		cin >> m >> k;
		while(m>0){
			s+=k;
			m--;
		}
	}
	
	for(int i=0;i<=(s.size()-1)/2;i++){
		if(s[i]!=s[s.size()-i-1]) cnt++;
		
	}
	cout << cnt;
	return 0;
}
 
