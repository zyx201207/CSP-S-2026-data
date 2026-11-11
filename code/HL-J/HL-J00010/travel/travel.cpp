#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[2],b[3],c[2],d[3];
	cin>>a[1]>>a[2]>>b[1]>>b[2]>>b[3]>>c[1]>>c[2]>>d[1]>>d[2]>>d[3];
	if(a[1]==c[1]&&a[2]==c[2]){
		cout<<"1";
		if(b[1]==d[1]&&b[2]==d[2]){
			cout<<"1";
			if(b[3]-'0'<='C'-'0'&&d[3]-'0'<='C'-'0'||d[3]-'0'>='D'-'0'&&b[3]-'0'>='D'-'0'){
				cout<<"1";
				if(b[3]-'0'+1==d[3]-'0'||b[3]-'0'-1==d[3]-'0')
			    {
				    cout<<"1";
			    }
			    else{
			    	cout<<"0";
			    }
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
    }
    else{
    	cout<<"0000";
    }
    return 0;
}
