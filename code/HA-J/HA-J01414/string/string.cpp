#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	string l;
	int n,a,cnt=0;
	char c;
	cin >>n;
	for (int i=0;i<n;i++){
		cin >>a>>c;
		for (int j=0;j<a;j++){
			l+=c;
		}
	}
	if (1){						//aabbc
		for (int i=0;i<l.length()/2;i++){
			if (l[i]!=l[l.length()-1-i]){
				cnt ++;
			}
		}
	}
	
	
	//else {
	//	for (int i=0;i<l.length()/2;i++){
	//		if (l[i])
	//	}
	//}
	cout <<cnt;
	
	
	return 0;
}
