#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
bool flag1,flag2,flag3,flag4;
bool check1(string a,string b){
	return a==b;
} 
bool check2(string a,string b){
	string t1,t2;
	t1=a[0]+a[1],t2=b[0]+b[1];
	return t1==t2;
}
bool check3(string a,string b){
	char t1,t2;
	t1=a[2],t2=b[2];
	if(t1=='D'){
		if(t2=='F'){
			return true;
		}else{
			return false;
		}
	}else if(t1=='F'){
		if(t2=='D'){
			return true;
		}else{
			return false;
		}
	}else{
		if(t2=='D'||t2=='F'){
			return false;
		}else{
			return true;
		}
	}
}
bool check4(string a,string b){
	char t1,t2;
	t1=a[2],t2=b[2];
	if(t1=='D'||t1=='F'){
		return true;
	}else{
		if(t1=='A'&&t2=='B'){
			return true;
		}else if(t1=='B'&&(t2=='C'||t2=='A')){
			return true;
		}else if(t1=='C'&&t2=='B'){
			return true;
		}
		return false;
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(check1(c1,c2)){
		flag1=1;
		if(check2(s1,s2)){
			flag2=1;
			if(check3(s1,s2)){
				flag3=1;
				if(check4(s1,s2)){
					flag4=1;
				}
			}
		}
	} 
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
