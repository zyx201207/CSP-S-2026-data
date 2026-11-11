#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool f(int a,int b){
	int s1,s2;
	while(a/2){
		if(a&1)s1++;
		a=a>>1;
	}
	while(b/2){
		if(b&1)s2++;
		b=b>>1;
	}
	return s1<s2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long s=1073741823;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,f);
	for(int i=0;i<m;i++){
		s&=a[i];
	}
	cout<<s;
return 0;
} 
