#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d; 
	int l = (a[0]-'0')*10+a[1]-'0';
	int l1 = (c[0]-'0')*10+c[1]-'0';
	if(l==l1){
		cout<<1;
		int l = (b[0]-'0')*10+b[1]-'0';
		int l1 = (d[0]-'0')*10+d[1]-'0';
		if(l==l1){
			cout<<1;
			int l = b[2]-'A';
			int l1 = d[2]-'A';
			if(l<3&&l1<3){
				cout<<1; 
				if(b[2]+1==d[2]||b[2]-1==d[2]){
					cout<<1;
				}else cout<<0;
			}else if(l>3&&l1>3){
				cout<<1;
				if(b[2]+1==d[2]||b[2]-1==d[2]){
					cout<<1;
				} else cout<<'0';	
			}else cout<<"00";
		}else{
			cout<<"000";
		}
	}else{
	    cout<<"0000";
	}
	return 0;
}
