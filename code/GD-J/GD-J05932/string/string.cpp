#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long size;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string si;
		cin>>x>>si;
		size+=x;
		for(int i=1;i<=x;i++){
			s+=si;
		}
	}
	if(size%2==0){
		int l=size/2-1;
		int r=size/2;
		for(int i=l,j=r;i>=0,j<size;i--,j++){
			if(s[i]!=s[j]) cnt++;
		}cout<<cnt;
	}else{
		int l=size/2-1;
		int r=size/2+1;
		for(int i=l,j=r;i>=0,j<size;i--,j++){
			if(s[i]!=s[j]) cnt++;
		}cout<<cnt;
	}
	return 0;
}
