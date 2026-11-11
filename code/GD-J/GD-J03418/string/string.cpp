#include<bits/stdc++.h>
using namespace std;
int n;
string a="0";
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	int mm;
	char ss;
	cin>>mm>>ss;
	a[0]=ss;
	for(int i=1;i<=mm-1;i++) a+=ss;
	for(int i=1;i<=n-1;i++){
		int m;
		string s;
		cin>>m>>s;
		for(int i=1;i<=m;i++){
			a+=s;
		}
	}
	string l,r;
	int len=a.length();
	int mid=len/2;
	if(len%2==0){
		l=a.substr(0,mid);
	    r=a.substr(mid);
	}
	else {
		l=a.substr(0,mid);//×ó°ë 
		r=a.substr(mid+1);
	}
	string rr=l.substr(mid-1,mid-1);
	
	for(int i=mid-2;i>=0;i--){
		rr+=l[i];
	}
	//cout<<rr;
	int ans=0;
	for(int i=0;i<mid;i++){
		if(rr[i]!=r[i]) ans++;
	}
	cout<<ans;
	return 0;
}
