#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char AF[5] = {'A','B','C','D','F'};
	string Rc1,Rs1,Xc2,Xs2;
	cin >> Rc1 >> Rs1 >> Xc2 >> Xs2;
	if (Rc1 != Xc2){
		cout << "0000";
	}
	else{
		cout << 1;
		if (Rs1.substr(0,2) != Xs2.substr(0,2)){
			cout << "000";
		}
		else{
			cout << 1;
			int RAF,XAF;
			for (int i = 0;i < 5;i++){
				if (Rs1[2] == AF[i]){
					RAF = i;	
				}
				if (Xs2[2] == AF[i]){
					XAF = i;
				}
			}
			if ((RAF < 3 && XAF > 2) || (RAF > 2 && XAF < 3)){
				cout << "00";
			}
			else{
				cout << 1;
				if (max(RAF,XAF) - min(RAF,XAF) == 1){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
		}
	}
	return 0;
}
