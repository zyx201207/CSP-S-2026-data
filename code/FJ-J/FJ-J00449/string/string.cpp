#include<bits/stdc++.h>
using namespace std;
int n,a[200005],kd;
char c[200005];
bool l[30];
long long tl[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		tl[c[i]-'a']+=a[i];
		if(!l[c[i]-'a']){
			kd++;
			l[c[i]-'a']=1;
		}
	}
	if(n==1||kd==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(n%2==0){
			cout<<max(a[1],a[2])-n/2;
			return 0;
		}
		else{
			cout<<min(a[1],a[2]);
			return 0;
		}
	}
	if(kd==2){
		cout<<min(tl[c[1]-'a'],tl[c[2]-'a']);
		return 0;
	}
	cout<<0;
	return 0;
}
