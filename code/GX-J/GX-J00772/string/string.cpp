#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long b[200005]={};
	string a,cmp="";
	long long cnt=0;
	for(int i=0;i<n;i++){
		cin>>b[i];
		cin>>a;
		cnt+=b[i];
		for(int l=0;l<b[i];l++){
			cmp+=a;
		}
	}
	long long cmt=0;
	long long cntb=cnt/2;
	for(int i=0;i<cntb;i++){
		if(cmp[i]!=cmp[cnt-i-1])cmt++;
	}
	cout<<cmt;
	return 0;
}

