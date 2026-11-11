#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
string b[500005],s;
bool f,f1;
int chw(string a){
	int cnt=0,len=a.size();
	for(int i=0,j=len-1;i<=j;i++,j--){
		if(a[i]!=a[j]) cnt++;
	}
	return cnt;
}

int main(){
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>n;
	cin>>a[0]>>b[0];
	for(int i=1;i<n;i++){
		cin>>a[i]>>b[i];
			if(b[i]!=b[i-1])
			f=1;
			if(a[i]!=a[i-1])
			f1=1;
	}
	if(f1==0){
		for(int i=0;i<n;i++){
			s+=b[i];
	}
		cout<<chw(s)*a[1];
		return 0;
	}
	else{
		for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	}
	if(!f){
		cout<<0;
		return 0;
	}
//	cout<<s<<1212<<endl;
	cout<<chw(s);
	return 0;
}
