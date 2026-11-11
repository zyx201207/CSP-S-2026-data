#include<bits/stdc++.h>
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a,c,s,t;
	char b[1005],d[1005];
	cin>>a;
	for(long long i=1;i<=3;i++){
		cin>>b[i];
	}
	cin>>c;
	for(long long i=1;i<=3;i++){
		cin>>d[i];
	}
	if(a==c){
		cout<<1;
		s=(b[1]-'0')*10+(b[2]-'0');
		t=(d[1]-'0')*10+(d[2]-'0');
		if(s==t){
			cout<<1;
			if(b[3]>='A'&&b[3]<='C'&&d[3]>='A'&&d[3]<='C'||b[3]>='D'&&b[3]<='F'&&d[3]>='D'&&d[3]<='F'){
				cout<<1;
				if(int(b[3])+1==int(d[3])||int(d[3])+1==int(b[3])){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
		    cout<<"000";
		    return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
    return 0;
}
