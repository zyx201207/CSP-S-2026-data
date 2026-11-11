#include<bits/stdc++.h>
using namespace std;
long long n,L,ans;
string str;
struct node{
	char c;
	int num;
}p[200005];
char att(int s){
	for(int i=0;;i++){
		if(s<=p[i].num)return p[i].c;
		s-=p[i].num;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p[i].num>>p[i].c;
		L+=p[i].num;
	}
	int mid=L/2;
	for(int i=0;i<mid;i++){
//		cout<<att(i)<<att(L-i)<<endl;
		if(att(i)!=att(L-i))ans++;
	}
	cout<<ans;
	return 0;
}
/*
1a 2
*/
