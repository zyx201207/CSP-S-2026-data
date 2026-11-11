#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string aa,ab,ba,bb;
	cin >> aa >> ab >> ba >> bb;
	int a=0,b=0;
	for(int i=0;i<aa.size();i++){
		a=a*10+(int)(aa[i]-'0');
	} 
	for(int i=0;i<ba.size();i++){
		b=b*10+(int)(ba[i]-'0');
	}
	if(a!=b){
		cout << "0000";
	}else{
		cout << 1;
		int c=0,d=0;
		for(int i=0;i<ab.size()-1;i++){
			c=c*10+(int)(ab[i]-'0');
		}
		for(int i=0;i<bb.size()-1;i++){
			d=d*10+(int)(bb[i]-'0');
		}
		if(c!=d){
			cout << "000";
		}else{
			cout << 1;
			char sa=ab[ab.size()-1],sb=bb[bb.size()-1];
			int cnta=0,cntb=0,cntc=0,cntd=0,cnte=0;
			if(sa=='A'){
				cnta++;
			}else if(sa=='B'){
				cntb++;
			}else if(sa=='C'){
				cntc++;
			}else if(sa=='D'){
				cntd++;
			}else{
				cnte++;
			}
			if(sb=='A'){
				cnta++;
			}else if(sb=='B'){
				cntb++;
			}else if(sb=='C'){
				cntc++;
			}else if(sb=='D'){
				cntd++;
			}else{
				cnte++;
			}
			if(cnta+cntb+cntc==1){
				cout << "00";
			}else{
				cout << "1";
				if(cnta==cntb&&cnta==1){
					cout << 1;
				}else if(cntb==cntc&&cntb==1){
					cout << 1;
				}else if(cntd==cnte&&cntd==1){
					cout << 1;
				}else{
					cout << 0;
				}
			}
		}
	}
	return 0;
} 
//02 01A 02 01B
