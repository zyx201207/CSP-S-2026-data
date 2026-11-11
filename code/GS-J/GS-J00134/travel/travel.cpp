#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int n,m,c,b,a[1005];
	string s;
	cin>>n;
	cin>>c;
	cin>>s[1];
	cin>>m;
	cin>>b;
	cin>>s[2];
	for(int i=0;i<=2;i++){
		if(s[i]=='A'){
			a[i]=1;
		}
			if(s[i]=='B'){
			a[i]=2;
		}
			if(s[i]=='C'){
			a[i]=3;
		}
			if(s[i]=='D'){
			a[i]=11;
		}
			if(s[i]=='F'){
			a[i]=12;
		}
	}
	cout<<a[1]<<a[2]<<endl;
	if(n==m){
		if(c==b){
			if(a[1]<9&&a[2]<9||a[1]>9&&a[2]>9){
				if(a[1]==a[2]+1||a[1]==a[2]-1){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}

