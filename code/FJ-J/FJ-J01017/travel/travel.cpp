#include <iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	char a[4],b[4];
	cin>>n>>a>>m>>b;
	if(n == m) cout<<1;
	else{
		cout<<"0000";
		return 0;	
	}
	int n1 = int(a[0]+a[1]);
	int m1 = int(b[0]+b[1]);
	int n2 = int(a[2]-'A'+1);
	int m2 = int(b[2]-'A'+1);
	if(n1 == m1 ){
		cout<< 1;
		if(n2 <= 3 && m2 <= 3){
			cout << 1;
			if(n2+1 == m2 && n2 != 3|| n2 -1 == m2) cout << 1;
			else cout<<0;
		}
		else if(n2 > 3 && n2 <= 5 && m2 > 3 && m2 <= 5){
			cout << 1;
			if(n2+1 == m2 && n2 != 4|| n2 -1 == m2 ) cout << 1;
			else cout<<0;	
		}
		else cout <<"00";
	}
	else cout<<"000";
	return 0;
	fclose(stdin);
	fclose(stdout);
}
