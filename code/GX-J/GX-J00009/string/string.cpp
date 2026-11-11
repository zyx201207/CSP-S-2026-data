#include<bits/stdc++.h>
using namespace std;
const long long maxn = 2*1e5;
long long a[maxn] = {};
char c[maxn] = {};
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n = 0,b=0,cnt=0,d = 0;
	string s = "";
	cin >> n;
	for(int i = 1;i <=n;i++){
		cin >> a[i] >> c[i];
		for(int j = 1;j <= a[i];j++){
			s = s+c[j];
			
		}
	}	
	if(s.size()%2==0){
		b = s.size()/2;
		d = s.size()/2;
		for(int i = 1;i <=int(s.size()/2);i++){
			if(s[b]!= s[d]){
				cnt++;
			}
			b--;
			d++;
		}
	}else{
		b = s.size();
		d = s.size()/2+2;
		for(int i = 1;i <=int(s.size()/2);i++){
			if(s[b]!= s[d]){
				cnt++;
			}
			b--;
			d++;
		}		



		
		
	}	
	
	cout << cnt;	
	

	
	
	return 0;
}
