#include <bits/stdc++.h>
using namespace std;
string b,s,bb,ss;
int a[5],p,pp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> b >> s >> bb >> ss;
	if(b[0] == bb[0] && b[1]==bb[1]){
		a[1] = 1;
	}else{
		for(int i = 1;i<=4;i++){
			cout << a[i];
		}
		return 0;
	}
	
	
	if(s[0]==ss[0]&&s[1] == ss[1]){
		a[2] = 1;
	}else{
		for(int i = 1;i<=4;i++){
			cout << a[i];
		}
		return 0;
	}
		
	
	p = int(s[2]);
	pp = int(ss[2]);
	if(p<=67 && pp<=67){
		a[3] = 1;
	}else if(p>67&&p<=70&&pp>70&&pp<=70){
		a[3] = 1;
	}else{
		for(int i = 1;i<=4;i++){
			cout << a[i];
		}
		return 0;
	}
		

	if(abs(p-pp)==1) a[4] = 1;
	for(int i = 1;i<=4;i++){
		cout << a[i];
	}
	return 0;

}
