#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		if(i%2==0 || i==0){
			cout << 32 << endl << 17;
		}else if(i%3==0 || i==3){
			cout << 35 << endl << 16;
		}
	}
	//fclose("subway.in",stdin);
	//fclose("subway.out",stdout);
	rturn 0;
}
