#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen ("travel.in","w",stdin);
	freopen ("travel.out","r",stdout);
	string ca,sa,cb,sb;
	cin >>ca>>sa>>cb>>sb;
	if (ca[0]*10+ca[1]==cb[0]*10+cb[1]){
		cout <<1;

	}else{
		cout <<"0000";
		return 0;
	} 
	if (sa[0]*10+sa[1]==sb[0]*10+sb[1]){
		cout <<1;
	}else {
		cout <<"000";
		return 0;
	}
	if(sa[2]<'D' && sb[2]<'D'){
		cout <<1;
		if(sa[2]-1==sb[2] || sa[2]+1==sb[2]){
		cout <<1;
		}else {
			cout <<0;
			return 0;
		}
	}else {
		cout <<"00";
		return 0;
	}
	if (sa[2]>'C' && sb[2]>'C'){
		cout <<11;
	}else {
		cout <<"00";
		return 0;
	}
	///if(sa[2]-1==sb[2] || sa[2]+1==sb[2]){
	//	cout <<1;
	//}else {
	//	cout <<0;
	//}
	return 0;
}
