#include<bits/stdc++.h>
using namespace std;
string er(int a){
	string st;
	int i=1;
	while(a>0){
		st=to_string(a%2)+st;
		a-=a%2;
		a/=2;
		i++;
	}
	return st;
}
string yu(string a,string b){
	string st;
	if(a.size()<b.size())swap(a,b);
	for(int i=1;i<=a.size()-b.size();i++){
		b="0"+b;
	}
	for(int i=0;i<a.size();i++){
		if(a[i]==b[i])st+='1';
		else st+='0';
	}
	return st;
}
int h(string st){
	int sum=0,j=0;
	for(int i=st.size()-1;i>=0;i--){
		sum+=(st[i]-'0')*pow(2,j);
		j++;
	}
	return sum;
}
int yi(string st){
	int sum=0;
	for(int i=0;i<st.size();i++){
		if(st[i]=='1')sum++;
	}
	return 0;
}
string ioi;
string r[200005];
int n,m,a[200005],ma[6];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		r[i]=er(a[i]);
		if(r[i]==r[i+1]){
			cout<<a[i];
			return 0;
		}
	}
	for(int i=0;i<pow(2,m);i++){
		string t=er(i);
		int f[m],k=0;
		if(yi(t)==m){
			for(int j=0;j<t.size();j++){
				if(t[j]=='1'){
					f[k]=j;
					k++;
				}
			}
			ioi=yu(r[f[0]],r[f[1]]);
			for(int j=2;j<m;j++){
				ioi=yu(ioi,r[f[j]]);
			}
			if(m<h(ioi))m=h(ioi);
		}
	}
	cout<<m;
	return 0;
}
