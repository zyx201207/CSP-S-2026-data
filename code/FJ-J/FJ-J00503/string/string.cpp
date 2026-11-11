#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt=0,num=0;
char c[200005];
int ac(int x){
	int k=0,cn=0,js=0;
	char q1,q2;
	int x1=2*(num/2)-x;
	while(cn<=x1){
		if(x1<=cn+a[k]){
			q1=c[js];
			break;
		}
		cn+=a[k];
		js++;
	}
	js=0;
	cn=0;
	while(cn<=x){
		if(x<=cn+a[k]){
			q2=c[js];
			break;
		}
		cn+=a[k];
		js++;
	}
	if(q1==q2) return 1;
	else return 0;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	for(int i=num/2;i<num;i++){
		if(ac(i)==0){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
