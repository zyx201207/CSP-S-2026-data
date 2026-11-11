#include<bits/stdc++.h>
using namespace	std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	string s,s1,c,c1,cc,ss,z,x;
	int ans=0,cnt=0;
	cin>>s>>s1>>c>>c1;
	if(s==c){
		cout<<1<<" ";
	}else cout<<0<<" ";
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='0'||s1[i]=='1'||s1[i]=='2'||s1[i]=='3'||s1[i]=='4'||s1[i]=='5'||s1[i]=='6'||s1[i]=='7'||s1[i]=='8'||s1[i]=='9'||s1[i]=='10'||s1[i]=='11'||s1[i]=='12'||s1[i]=='13'||s1[i]=='14'||s1[i]=='15'||s1[i]=='16'||s1[i]=='17'||s1[i]=='18'){
			ss+=s1[i];
		}
	}
	for(int i=0;i<c1.size();i++){
		if(c1[i]=='0'||c1[i]=='1'||c1[i]=='2'||c1[i]=='3'||c1[i]=='4'||c1[i]=='5'||c1[i]=='6'||c1[i]=='7'||c1[i]=='8'||c1[i]=='9'||c1[i]=='10'||c1[i]=='11'||c1[i]=='12'||c1[i]=='13'||c1[i]=='14'||c1[i]=='15'||c1[i]=='16'||c1[i]=='17'||c1[i]=='18'){
			cc+=c1[i];
		}
	}
	if(ss==cc&&s==c){
		cout<<1<<" ";
	}else cout<<0<<" ";
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='A'&&s1[i]<='F'){
			z+=s1[i];
		}
	}
	for(int i=0;i<c1.size();i++){
		if(c1[i]>='A'&&c1[i]<='F'){
			x+=c1[i];
		}
	}
	for(int i=0;i<z.size();i++){
		if(z[i]>='A'&&z[i]<='C'){
			ans=1;
		}else ans=2;
	}
	for(int i=0;i<x.size();i++){
		if(x[i]>='A'&&x[i]<='C'){
			cnt=1;
		}else cnt=2;
	}
	if(ans==cnt&&ss==cc&&s==c){
		cout<<1<<" ";
	}else cout<<0<<" ";
	for(int i=0;i<=max(z.size(),x.size());i++){
		if(z[i]=='A'&&x[i]=='B'||z[i]=='B'&&x[i]=='C'||z[i]=='D'&&x[i]=='F'||x[i]=='A'&&z[i]=='B'||x[i]=='B'&&z[i]=='C'||x[i]=='D'&&z[i]=='F'){
		if(ans==cnt&&ss==cc&&s==c){
			cout<<1<<" ";
			break;
		}else {
			cout<<0<<" ";
			break;
		}
	}else {
		cout<<0<<" ";
		break;
	}
	}

	return 0;
}


//02 01A 02 01B


//02 01c 02 01D




//172.16.12.5
