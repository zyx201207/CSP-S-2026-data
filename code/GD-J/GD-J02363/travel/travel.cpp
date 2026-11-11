#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int an,bn,cn,dn;
	if(a[0] == '0')an = a[1]+'0';
	else an = (a[0]+'0')*10+(a[1] + '0');
	
	if(c[0] == '0') cn = c[1] + '0';
	else cn = (c[0]+'0')*10+(c[1] + '0');
	
	if(b[0] == '0') bn = b[1] + '0';
	else bn = (b[0]+'0')*10+(b[1] + '0');
	
	if(d[0] == '0') dn = d[1] + '0';
	else dn = (d[0]+'0')*10+(d[1] + '0');//转换 
	
	
	if(an == cn) cout<<'1';
	else cout<<'0';//同节车厢 
	
	char bz = b[2], dz = d[2];
	if(bn == dn){
		cout<<'1';//同排
		if(bz == 'A'){
			if(dz == 'B' || dz == 'C') cout<<'1';
			else cout<<'0';
		}else if(bz == 'B'){
			if(dz == 'A' || dz == 'C') cout<<'1';
			else cout<<'0';
		}else if(bz == 'C'){
			if(dz == 'A' || dz == 'B') cout<<'1';
			else cout<<'0';
		}else if(dz == 'D'){
			if(dz == 'F') cout<<'1';
			else cout<<'0';
		}else if (dz == 'F'){
			if(dz == 'D') cout<<'1';
			else cout<<'0'; 
		}//同侧
	}else{
		cout<<'0'<<'0';
	}
	
	if(bn == dn){//相邻 
		if(bz == 'A'){
			if(dz == 'B') cout<<'1';
			else cout<<'0';
		}else if(bz == 'B'){
			if(dz == 'A' || dz == 'C') cout<<'1';
			else cout<<'0';
		}else if(bz == 'C'){
			if( dz == 'B') cout<<'1';
			else cout<<'0';
		}else if(dz == 'D'){
			if(dz == 'F') cout<<'1';
			else cout<<'0';
		}else if (dz == 'F'){
			if(dz == 'D') cout<<'1';
			else cout<<'0'; 
		}
	}else{
		cout<<'0';
	}
	return 0;
} 
