#include<bits/stdc++.h>
using namespace std;
bool ishw(string a){
	string b=a;
	reverse(a.begin(),a.end());
	if(a==b)
		return true;
	else{
		reverse(a.begin(),a.end());
		return false;
	}
}
string adds(int a,string b){
	string c;
	for(int i=0;i<a;i++){
		c+=b;
	}
	return c;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,c;
	int a,n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		s+=adds(a,c);
	}
	if(ishw(s)){
		cout<<0;
		return 0;
	}
	int l=s.size(),l1,l2;
	if(l%2==1){
		l1=l/2;
		l2=l1+1;
	}
	else{
		l1=l/2;
		l2=l/2;
	}
	string s1=s.substr(0,l1),s2=s.substr(l2);
	reverse(s2.begin(),s2.end());
	int cnt=0;
	for(int i=0;i<l1;i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
