#include<bits/stdc++.h>
using namespace std;
struct j{
	int k;
	char c;
};
j a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n,k=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].k>>a[i].c;
		for(int j=0;j<a[i].k;j++)s+=a[i].c;
	}
	if(s.size()%2==0){
		int i=s.size()/2-1,j=s.size()/2;
		while(i>=0){
			if(s[i]!=s[j])k++;
			i--;
			j++;
		}
	}else{
		int i=s.size()/2-1,j=s.size()/2+1;
		while(i>=0){
			if(s[i]!=s[j])k++;
			i--;
			j++;
		}
	}cout<<k;
	return 0;
}
