#include<bits/stdc++.h> 
using namespace std; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,k;
	string a,s;
	cin >> n >> a >> m >> s;
	if(a[2] - s[2]<=1&&s[2] - a[2]>=-1||a[2]=='D'&&s[2]=='F'){
		if(a[2]=='D'&&s[2]=='C'||a[2]=='C'&&s[2]=='D'){
			k=0;
		}else{
			k=1;
		}
	}else if(a[2]=='D'&&s[2]=='F'||a[2]=='F'&&s[2]=='D'){
		k=1;
	}else{
		k=0;
	}
	
	if(n == m){
		cout << "1";
		if(a[0] == s[0]&&a[1] == s[1]){
			cout << "1";
			if(k==1){
				cout << "11";
			}else{
				if(a[2]<='C'&&s[2] <= 'C'||a[2]>='D'&&s[2] >= 'D'){
					cout << "10";
				}else{
					cout << "00";
				}
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
	return 0;
}
