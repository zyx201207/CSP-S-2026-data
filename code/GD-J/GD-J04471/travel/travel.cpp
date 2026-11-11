#include<bits/stdc++.h>
using namespace std;


string cn,sn,cm,sm;
bool qf,qs,qt,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cn >> sn >> cm >> sm;
	if(cn == cm) qf = 1;
	if(qf && sn[0] == sm[0] && sn[1] == sm[1]) qs = 1;
	if(qs && (sn[2] <= 'C' && sm[2] <= 'C') || (sn[2] >= 'D' && sm[2] <= 'D')){
		qt = 1;
	}
	if(qt && (abs(sn[2] - sm[2]) <= 1 || sn[2] == 'F' || sm[2] == 'F'))
		q = 1;
	cout << qf << qs << qt << q;
	return 0;
} 

//(sn[2] >= 'A' && sn[2] <= 'B' && sm[2] >= 'A' && sm[2] <= 'B') || (sn[2] >= 'B' && sn[2] <= 'C' && sm[2] >= 'B' && sm[2] <= 'C') || (sn[2] >= 'D' && sn[2] <= 'E' && sm[2] >= 'D' && sm[2] <= 'E')
