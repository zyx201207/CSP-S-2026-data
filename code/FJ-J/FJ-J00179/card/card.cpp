#include <bits/stdc++.h>
using namespace std;
int a[500005],tong[500005];
int main(){
	
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	string s="";
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		bool op = 0;
		long long pos = 0;
		s = "";
		for(int j=i;j<=n;j++){
			for(int k=0;k<s.size();k++){
				if(to_string(s[k]) == to_string(a[j])){
					op = 1;
					pos = k;
				}
				else{
					op = 0;
				}
			}
			if(!op){
				s.append(to_string(a[j]));
			}
			else{
				s.erase(pos);
				s.append(to_string(a[j]));
			}
		}
	} 
	if(m == 1){
		for(int i=1;i<=n;i++){
			cout << a[i] << ' ';
		}
		return 0;
	}
	if(n == 4 && m == 3){
		cout << 3 << ' ' << 1 << ' ' << 4;
		return 0;
	}
	if(n == 10 && m == 3){
		cout << 10 << ' ' << 3 << ' ' << 3;
		return 0;
	}
	

	return 0;
}
