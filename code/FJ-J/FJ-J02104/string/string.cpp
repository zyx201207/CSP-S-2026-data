#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	char data;
	long long num;
}s[200005];
long long suo(int& l,int& r){
	long long k=min(s[l].num,s[r].num);
	s[l].num-=k; s[r].num-=k;
	if(s[l].num<=0) l++;
	if(s[r].num<=0) r--;
	return k;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a; char c;
		cin>>a>>c;
		s[i].data=c;
		s[i].num=a;
	}
	int l=0,r=n-1;
	long long ans=0;
	while(l<=r){
		if(s[l].data==s[r].data){
			suo(l,r);
		}else{
			ans+=suo(l,r);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
