#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);		
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	
	if(a==c){//1
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	
	string e,f;
	ll sum_=0;
	for(int i=0;i<2;i++){
		if(b[i]==d[i]){
			sum_++;
		}
	}
	char j,h;
		j=b[2];
		h=d[2];
	if(sum_!=2){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";

    }
	
	if(j=='C'||j=='B'||j=='A'){
		if(h=='C'||h=='B'||h=='A'){
			cout<<"1";
		
		}else if(j=='F'||j=='D'){
			if(h=='F'||h=='D'){
				cout<<"1";
			}
		}else{
			cout<<"00";
			return 0;
		}
		
	}
	if(abs((j-'0')-(h-'0'))==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	return 0;
}
