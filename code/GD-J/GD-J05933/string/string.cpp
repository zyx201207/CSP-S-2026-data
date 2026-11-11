#include<bits/stdc++.h>
using namespace std;
struct str{
	int l=0;
	string s;
}a[20010];
int n;
string c;
string front1="";
string end1="";
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].s;
	}
	for(int j=1;j<=(n+1)/2;j++){
		c="";
		for(int i=1;i<=a[j].l;i++){
			c=c+a[j].s;
		}
		for(int i=1;i<=a[n-j+1].l;i++){
			c=c+a[n-j+1].s;
		}
		c=front1+c+end1;
		for(int i=0;i<c.size()/2;i++){
			if(c[i]!=c[c.size()+1-i]){
				c[i]=c[c.size()+1-i];
				cnt++;
			}
		}
		if(a[j].l>=a[n+1-j].l){
			front1=a[j].s;
		}
		else if(a[j].l<a[n+1-j].l){
			end1=a[n-j+1].s;
		}
	}
	cout<<cnt;
	return 0;
}

