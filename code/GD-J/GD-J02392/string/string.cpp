#include<bits/stdc++.h>
using namespace std;
int n;
struct sc{
	int t;
	char c;
}s[200005];
sc f,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].t>>s[i].c;
	}
	int i=1,j=n;
	long long ans=0;
	do{
		if(f.t==0){
			f=s[i];
			i++;
		}
		if(b.t==0){
			b=s[j];
			j--;
		}
		
		int t=min(f.t,b.t);
		if(f.c != b.c)ans+=t;
		f.t-=t;b.t-=t;
	}while(i<=j || f.t>0 && b.t>0);
	cout<<ans;
}
