#include<bits/stdc++.h>
using namespace std;
long long n,ans,zl,le[200001],l[200001],r[200001];
char c[200001];
void f(int a,int b){
	if(abs(a-b)==1&&(le[a]==le[b])){
			ans+=le[a];
			return;
	}
	if(a==b){
		long long ll=n/2;
		long long p=ll-l[a]+1;
		long long q=r[a]-ll;
		if(p>q) ans+=p-q;
		else if(c[a]!=c[b])
			ans+=q-p;
		return;
	}
	if(le[a]>le[b]){
		if(c[a]!=c[b])
			ans+=le[b];
		le[a]-=le[b];
		f(a,b-1);
	}else if(le[b]>le[a]){
		if(c[a]!=c[b])
			ans+=le[a];
		le[b]-=le[a];
		f(a+1,b);
	}else{
		if(c[a]!=c[b]) ans+=le[a];
		f(a+1,b-1);
	}
}
int main(){
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	int n;
	cin>>n;
	long long k=1;
	for(int i=1;i<=n;i++){
		cin>>le[i]>>c[i];
		l[i]=k+1;
		r[i]=k+le[i];
		k=r[i];
	}
	f(1,n);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
