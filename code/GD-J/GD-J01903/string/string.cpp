#include <iostream>
#include <string>
using namespace std;
int n; string str; long long Tl, ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin>>n;
	for(int i=1; i<=n; i++){
		int a; char c;
		cin>>a>>c;
		
		Tl+=a;
		while(a--){
			str+=c;
		}
	}
	
	for(long long p=1; p<=Tl/2; p++){
		if(str[p-1]!=str[Tl-p]) ans++;
	}
	
	cout<<ans;
	
	return 0;
}
