#include <iostream>
using namespace std;

int n;
string s;
int size;
int ans;
void chack(){
	for(int i=0;i<=size/2;i++){
		if(s[i]!=s[size-i-1]){
			ans++;
		}
	}
}

int main() {
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	size=s.size();
	chack();
	cout<<ans;
	
	
	return 0;
}
