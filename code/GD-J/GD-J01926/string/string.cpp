#include <bits/stdc++.h>
using namespace std;
long long b[200005],n,mid,x=-1,y;
string a[200005],s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		for(int j=1;j<=b[i];j++)s+=a[i];
	}n=0;
	y=s.size();
	if(s.size()%2==1){
		mid=s.size()/2+1;
		for(int i=1;i<mid;i++){
			x++;
			y--;
			if(s[x]!=s[y])n++;
		}cout<<n;
		return 0;
	}else{
		mid=s.size()/2;
		for(int i=1;i<=mid;i++){
			x++;
			y--;
			if(s[x]!=s[y])n++;
		}cout<<n;
	}
	return 0;
}
