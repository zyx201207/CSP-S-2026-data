#include<bits/stdc++.h>
using namespace std;

int b1,b2,b3,b4;
char ca[5],sa[5],cb[5],sb[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> ca >> sa >> cb >> sb;
	//≥µœ· 
	if(ca[0] == cb[0] && ca[1] == cb[1])
		b1 = 1;
	//≈≈ 
	if(sa[0] == sb[0] && sa[1] == sb[1])
		b2 = 1;
	//≤‡ 
	if(('A' <= sa[2] && sa[2] <= 'C') && ('A' <= sb[2] && sb[2] <= 'C'))
		b3 = 1;
	if(('D' <= sa[2] && sa[2] <= 'E') && ('D' <= sb[2] && sb[2] <= 'E'))
		b3 = 1;
	//¡Ÿ 
	if(!((sa[2] == 'C' && sb[2] == 'D') || (sa[2] == 'D' && sb[2] == 'C')))
		if(abs(sa[2] - sb[2]) == 1)
			b4 = 1;
	
	if(b1){
		cout << b1;
		if(b2){
			cout << b2;
			if(b3){
				cout << b3;
				cout << b4;
			}else cout << 0 << 0;
		}else cout << 0 << 0 << 0;
	}else cout << 0 << 0 << 0 << 0;
}
