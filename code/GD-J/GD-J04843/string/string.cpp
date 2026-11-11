#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	int a1,b1,c1,sum,n,a2,b2,c2;
	cin >> n >> endl;
	cin >> a1 >> " " >> a2 >> endl;
	cin >> b1 >> " " >> b2 >> endl;
	cin >> c1 >> " " >> c2 >> endl;
	if(a2+b2+c2 = c2+b2+a2){
		cout << "0";
	}else{
		sum+=a1,b1,c1;
		cout << sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
