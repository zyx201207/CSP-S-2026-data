#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100];
string b[200100];
string makein(int x){
	string t="",m="";
	while(x){
		t+=x%2+'0',x=x/2;
	}
	for(int i=t.size()-1;i>=0;i--){
		m+=t[i];
	}
	return m;
}
int makeout(string x){
	int k=1,t=0;
	for(int i=x.size()-1;i>=0;i--){
		t+=(x[i]-'0')*k;
		k*=2;
	}
	return t;
}
string makeand(string t1,string t2){
	string t3;
	if(t1.size()>t2.size()){
		t3=t2;
	}else{
		t3=t1;
	}
	for(int i=0;i<min(t1.size(),t2.size());i++){
		if(t1[i]==0||t2[i]==0){
			t3[i]='0';
		}else{
			t3[i]='1';
		}
	}
	return t3;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	string s=makein(a[n]);
	for(int i=n-1;i>=n-m+1;i--){
		s=makeand(s,makein(a[i]));
	}
	cout<<makeout(s);
	return 0;
}
