#include <bits/stdc++.h>
using namespace std;
char a[4];
char b[4];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int aa=0,bb=0;
	cin >> aa;
	for(int i=1;i<=3;i++){
		cin >> a[i];
	}
	cin >> bb;
	for(int i=1;i<=3;i++){
		cin >> b[i];
	}
	int num1=int(a[1])*10-480+int(a[2])-48;
	int num2=int(b[1])*10-480+int(b[2])-48;
    if(aa==bb){
    	cout << "1";
    	if(num1==num2){
    		cout << "1";
    		if(a[3] <= 'C' && b[3] <= 'C'){
    			cout << "1";
    			if(abs(a[3]-b[3])==1){
    				cout << "1";
				}
				else{
					cout << "0";
				}
			}
			else if(a[3]>'C'&&b[3]>'C'){
				cout << "11";
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else {
	cout << "0000";
    }
    return 0;
}
