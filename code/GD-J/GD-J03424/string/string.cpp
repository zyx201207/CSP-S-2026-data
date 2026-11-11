#include <bits/stdc++.h>
using namespace std;
long long n,ans,sum,maxsum;
struct node{
	long long a;
	string c;
}b[200005];
bool cmp(node x,node y){
	return x.c<y.c;
}
string w;
bool f=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","l",stdout);
	cin >>n;
	for (int i=1;i<=n;i++){
		cin >>b[i].a>>b[i].c;
	}
	w=b[1].c;
	for (int i=1;i<=n;i++){
		if (b[i].c!=b[n-i+1].c){
			f=false;
			break;
		}
	}
	if (f){
		cout <<"0";
		return 0;
	}
	sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++){
		if (b[i].c!=b[i-1].c){
			sum=b[i].a;
		}
		else{
			sum+=b[i].a;
		}
		if (sum>maxsum){
			maxsum=sum;
			w=b[i].c;
		}
	}
	cout <<maxsum;
	return 0;
}
