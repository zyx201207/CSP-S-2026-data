#include <bits/stdc++.h>
using namespace std;

int n,num,add[200005];
char zf;
string str; 



int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string str;
	int num;
	char zf;
	for(int i = 1 ; i <= n ; i++){
		cin>>num>>zf;
		str = str+zf; 
		add[i] = add[i-1] + num; 
	}
	int cnt = 0;
	for(int i = 0 ; i < add[n]/2 ; i++){
		if(str[lower_bound(add+1,add+n+1,i)-add-1]  != str[lower_bound(add+1,add+n+1,add[n]-i)-add-1]){
		   	cnt++;
		}
	}
	cout << cnt ;
	return 0;
}



