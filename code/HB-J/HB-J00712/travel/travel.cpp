#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long int e;
	char a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}else{
		cout<<"1";
		if(b%10!=d%10||b/1%10!=b/10%10){
			cout<<"000";
		}else{
			cout<<"1";
			if(d!=b+1){
				cout<<"00";
			}else{
				cout<<"1";
				if(b==d+1||d==b+1){
					cout<<"1";
				}else{
					cout<<" ";
				}
			}
		}
	}
	return 0;
}
