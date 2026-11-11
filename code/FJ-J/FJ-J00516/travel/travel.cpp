#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
    int a=(int)s1[2];
    int b=(int)s2[2];
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]){
			if(s1[1]==s2[1]){
				cout<<1;
				if(a<=67&&b<=67){
					cout<<1;
					if(a-b==1||b-a==1){
						cout<<1;
					    }else{
					    	cout<<0;
						}
				    }else{
				    	cout<<0<<0;
					}
				if(a>=68&&b>=68){
				    cout<<1;
					if(a-b==1||b-a==1){
						cout<<1;
					    }else{
					    	cout<<0;
						}
				    }
			    }else{
					cout<<0<<0<<0;
					}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
